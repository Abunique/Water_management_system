
#include "wetflix_WiFi.h"
#include "user_defines.h"
#include <ArduinoJson.h> //ArduinoJson Library Source: https://github.com/bblanchon/ArduinoJson
#include "time.h"
#include "wetflix_time.h"
#include "wetflix_MAX17055.h"
#include "wetflix_TMF882X.h"
#include <esp_task_wdt.h> 
#include "wetflix_led.h"


unsigned long previousMillis;

bool stationConnected = false;
bool Client_status = 0;


AsyncWebServer server(80);

HTTPClient http;

WiFiClientSecure client;

String requestBody;

const char *soft_ap_ssid = "Wetflix_ConfigAP";
const char *soft_ap_password = "12345678";

const char* SERVER_NAME_1 = "https://3.135.196.37/api/v2/device/createUserDevice";//onboarding server
const char* SERVER_NAME_2 = "https://api.dev.wetflix.net/api/v2/device/createDeviceData";//data server

//variables to store value from the flash memory
 char WiFi_SSID[40]="";
 char WiFi_PWD[40]="";
 char WiFi_time_zone[10]="5:30";

// Custom parameter names
const char *param_devicename = "wifidevicename";
const char *param_Email = "wifiusername";
const char *param_WiFi_SSID = "wifissid";
const char *param_WiFi_PWD = "wifipassword";
const char *param_time_zone = "WifiDeviceTiming";

const char *devicename = "";
const char *Email="";
const char *wifissid="";
const char *wifipassword="";
const char *time_zone="";




void SPIFFS_read()
{
  if (SPIFFS.begin())
  {
    Serial.println("mounted file system");
    if (SPIFFS.exists("/userParameters.json"))
    {
      // file exists, reading and loading

      File configFile = SPIFFS.open("/userParameters.json", "r");
      if (configFile)
      {
        Serial.println("opened config file");
        size_t size = configFile.size();
        // Allocate a buffer to store contents of the file.
        std::unique_ptr<char[]> buf(new char[size]);

        configFile.readBytes(buf.get(), size);

        DynamicJsonDocument json(1024);
        auto deserializeError = deserializeJson(json, buf.get());
        serializeJson(json, Serial);
        if (!deserializeError)
        {
          Serial.println("\nparsed json");
          strcpy(WiFi_SSID, json["SSID"]);
          strcpy(WiFi_PWD, json["PWD"]);
          strcpy(WiFi_time_zone, json["time_zone"]); 
      }
      else
      {
        Serial.println("failed to load json config");
      }
      configFile.close();
    }
  }
  else
  {
    Serial.println("failed to mount FS");
  }
}
}


void SPIFFS_write()
{
  DynamicJsonDocument json(1024);

  json["SSID"] = wifissid;
  json["PWD"] = wifipassword;
  json["time_zone"] = time_zone;

  File configFile = SPIFFS.open("/userParameters.json", FILE_WRITE);
  if (!configFile)
  {
    Serial.println("failed to open config file for writing");
  }

  serializeJson(json, Serial);
  serializeJson(json, configFile);

  configFile.close();
}

void WiFiEvent(WiFiEvent_t event)
{
  switch (event)
  {
  case ARDUINO_EVENT_WIFI_AP_START:
    Serial.println("WiFi access point started");
    break;
  case ARDUINO_EVENT_WIFI_AP_STOP:
    Serial.println("WiFi access point  stopped");
    break;
  case ARDUINO_EVENT_WIFI_AP_STACONNECTED:
    Serial.println("Client connected");
    Client_status = 1;
    break;
  case ARDUINO_EVENT_WIFI_AP_STADISCONNECTED:
    Serial.println("Client disconnected");
    Client_status = 0;
    break;
  case ARDUINO_EVENT_WIFI_STA_CONNECTED:
    Serial.println("Connected to access point");
    stationConnected = true;
    break;

  default:
    break;
  }
}


void wm_setup()
{
 
  //reading WIFI_parameters,time zone from flash 
  SPIFFS_read();
 
  WiFi.softAP(soft_ap_ssid, soft_ap_password);
  // Web Server Root URL
  WiFi.begin(WiFi_SSID,WiFi_PWD);
  delay(500);
  
   if (strlen(WiFi_SSID) == 0)
   {
   //flashing html page in the WIFI_IP address
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Onboarding_page.html", "text/html"); });
   }
   else
{
 //flashing html page in the WIFI_IP address
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/Update_page.html", "text/html"); });
}
//getting entered details from the webpage on clicking submit button
  server.on("/submit", HTTP_POST, [](AsyncWebServerRequest *request)
            {
              int params = request->params();
              Serial.println(params);
              for (int i = 0; i < params; i++)
              {
                AsyncWebParameter *p = request->getParam(i);
                if (p->isPost())
                {
                  
                  if (p->name() == param_devicename)
                  {
                    devicename = p->value().c_str();
                    Serial.print("Device name set to : ");
                    Serial.println(devicename);
                  }
                
                  if (p->name() == param_Email)
                  {
                    Email = p->value().c_str();
                    Serial.print("username set to: ");
                    Serial.println(Email);
                  }
                
                  if (p->name() == param_WiFi_SSID)
                  {
                    wifissid = p->value().c_str();
                    Serial.print("wifissid to: ");
                    Serial.println(wifissid);
                  }
                
                  if (p->name() == param_WiFi_PWD)
                  {
                    wifipassword = p->value().c_str();
                    Serial.print("wifipassword set to: ");
                    Serial.println(wifipassword);
                  }

                  if (p->name() == param_time_zone)
                  {
                    time_zone = p->value().c_str();
                    Serial.print("time zone set to: ");
                    Serial.println(time_zone);
                  }
                }
              }
            
          
              WiFi.begin(wifissid, wifipassword);
              Serial.println("Connecting.........");
              delay(2000);

             // checking wifi status 
              if(WiFi.status() == WL_CONNECTED){
                  delay(100);
                 if (strlen(Email) != 0)//if email is entered in the html page,conditon is considered onboarding
                 {
                 String onboarding_reqq = Onboarding_req();//if connected ,sending http req-onboarding
                   if(send_httpData(SERVER_NAME_1,onboarding_reqq))
                    {
                      SPIFFS_write();
                      request->send(200, "text/plain", "Done. ESP will restart, connect to your router and go to IP address: "); 
                    delay(500);
                    
                    ESP.restart();
                     } 
                     else
                     {
                     request->send(400, "text/plain", "Onboarding request failure");//intimating onboarding failure in the web page
                     error_led() ;
                     Serial.println("Starting deep sleep due to onboarding request failure.");
                     esp_deep_sleep_start();
                     }
                 }
                 request->send(200, "text/plain", "Wifi_credentials saved!"); 
                 SPIFFS_write();
                 }
                 else
                {
                  Serial.println("Failed to connect.");//wifi connection failure
                 request->send(400, "text/plain", "Device Not connected to Wi-Fi, Please check credentials");
                 error_led() ;
                Serial.println("Starting deep sleep due to Network connectivity failure");
                esp_deep_sleep_start();
                } 
              });

  AsyncElegantOTA.begin(&server);    // Start OTA update
  server.begin();
}


/**
 * 	@fn                 - init_WiFi
 *
 * 	@brief			        - initialize the wifi with accesss point, station mode and wifi credentials.
 *
 *  @param[in]		      - none
 *
 *  @param[in]		      - none
 *
 *  @return             - none.
 */



void init_WiFi()
{
  WiFi.mode(WIFI_MODE_APSTA);
  WiFi.onEvent(WiFiEvent);
  esp_task_wdt_init(45, false);
  wm_setup();

}
/**
 * 	@fn                 - device_data
 *
 * 	@brief			        - get the device datas converted into json format.
 *
 *  @param[in]		      - battery_data
 *
 *  @param[in]		      - sensor_data
 * 
 *  @param[in]		      - time
 * 
 *  @return             - returns the string of overall device data.
 */
/*TODO
 change the device id to mac address. 
*/

String device_data()
{

    StaticJsonDocument<200> doc;
    
    doc["deviceid"] = String(WiFi.macAddress());
    doc["waterlevel"] = String(get_sensor_data());
    doc["errorcondition"] = String(init_sensor())+String(!SPIFFS.begin())+String(Time_error_flag);
    doc["batterystatus"] = String(get_battery_data());
    doc["wifistatus"] = String(WiFi.RSSI());
    doc["version"] = "v001";
    doc["createdtime"] = String(get_epoch_Time());
   
   serializeJson(doc, requestBody);
    // Serial.print ln("the JSON value of a Device data");

    Serial.println(requestBody);

    return requestBody;
}


String Test_data;

String sensorData()
{
  //Create a JSON document of size 200 bytes, and populate it
  //See https://arduinojson.org/.
  StaticJsonDocument<200> doc;

    doc["deviceid"] = "30";
    doc["waterlevel"] = String(get_sensor_data());
    doc["errorcondition"] = String(init_sensor())+String(!SPIFFS.begin())+String(Time_error_flag);
    doc["batterystatus"] = String(get_battery_data());
    doc["wifistatus"] = String(WiFi.RSSI());
    doc["version"] = "v001";
    doc["createdtime"] = String(get_epoch_Time());

      serializeJson(doc,Test_data);

      Serial.println(Test_data);

      return Test_data;
}



String onboarding_data;

String Onboarding_req()
{
   //Create a JSON document of size 200 bytes, and populate it
  //See https://arduinojson.org/.
  StaticJsonDocument<200> doc;
    
    doc["email"] = Email;
    doc["devicename"] =  devicename ;
    doc["deviceid"] = String(WiFi.macAddress());
    doc["iswifi"]= "true";
    

      serializeJson(doc,onboarding_data);

      Serial.println(onboarding_data);

      return onboarding_data;
}


/**
 * 	@fn                 - send_httpData
 *
 * 	@brief			        - sends the device data via http protocol.
 *
 *  @param[in]		      - battery_data 
 *
 *  @param[in]		      - sensor_data
 *
 *  @param[in]		      - time
 * 
 *  @return             - returns one if the data sent successfully else two will be returned.
 */


uint8_t send_httpData(const char* server_url,String send_data)
{

  client.setInsecure();
  // Begin HTTP connection

  http.begin(client, server_url);

  // If you need an HTTP request with a content type: application/json, use the following:
  http.addHeader("Content-Type", "application/json");
  // publishMessage();

  int httpResponseCode = http.POST(send_data);
  if (httpResponseCode > 0)
  {
    String response = http.getString(); // Get the response to the request
    Serial.println(httpResponseCode);   // Print return code
    Serial.println(response);
    http.end();                  // Close HTTP connection
    if (httpResponseCode == 400) // Print request answer
    {
      return 0;
    }
    else if (httpResponseCode == 200)
      return 1;
  }
  else
  {
    Serial.print("Error on sending POST: ");
    Serial.println(httpResponseCode);
    http.end(); // Close HTTP connection
    return 0;
  }

  return 0;
}


/**
 * 	@fn                 - check_wifiStatus
 *
 * 	@brief			        - check Wifi Connection status every 500ms for 2 minutes .
 *
 *  @param[in]		      - none
 *
 *  @param[in]		      - none
 *
 *  @return             - returns one if the wifi connected else two will be returned.
 */

int8_t check_wifiStatus()
{
  //check Wifi Connection status every 500ms for 2 minutes
  if (millis() - previousMillis >= WiFi_STATUS_CHECK_TIME)
  {
    static int i = 0;
    if (WiFi.status() != WL_CONNECTED)
    {
      i++;
      previousMillis = millis();
      if (i == 240)
      {
        i = 0;
        return 0;
      }
      return 2;
    }
    return 1;
  }
  return -1;
}

/**
 * 	@fn                 - sendData
 *
 * 	@brief			        - checks Wifi Connection and device data sent status.
 *
 *  @param[in]		      - battery_data
 *
 *  @param[in]		      - send_data
 *
 *  @param[in]		      - time
 *
 *  @return             - returns stauts of the send_data function.
 */

uint8_t sendData(String send_data)
{
   int8_t connection_status = check_wifiStatus();
  if ( connection_status == 0)
  {
 
    return 0;
  }
  else if(connection_status == 1)
  {                       
  if (send_httpData(SERVER_NAME_2,send_data) == 0)
  {
    delay(500);
    if (send_httpData(SERVER_NAME_2,send_data) == 0)
      return 1;
  }
  else
      return 2;
  }
    return 0;
}
