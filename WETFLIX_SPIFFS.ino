#include <FS.h>                   //this needs to be first, or it all crashes and burns...
#include <SPIFFS.h>
#include <ArduinoJson.h>


char WiFi_SSID[40]="wifissid";
 char WiFi_PWD[40]="wifipassword";
 char WiFi_time_zone[40]="wifi_time_zone";

 String wifissid="wifissid";
String wifipassword = "wifipassword";
String time_zone = "wifi_time_zone";

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



void setup()
{
  Serial.begin(115200);
  SPIFFS_read();
  SPIFFS_write();
}

void loop()
{
}
