// Wetflix V1.0
// Send random data to AWS cloud and test
// Setup SPIFFS
// Setup Wi-Fi manager and test with Wi-Fi credentials
// Add additional user parameters using Wi-Fi manager and verify the data
// Setup GSM and test module
// Send data via SMS and verify SMS received
// Setup OTA and test

#include <Arduino.h>
#include "wetflix_WiFi.h"
#include "wetflix_MAX17055.h"
#include <WiFiClientSecure.h>
#include "user_defines.h"
#include "wetflix_TMF882X.h"
#include "wetflix_time.h"
#include "wetflix_led.h"


const uint8_t Reset_pin = 4;//reset button
bool Request= false;

void IRAM_ATTR isr() {
  // Serial.print("interrupt");
 Request = true;
}

unsigned long waitStart = 0; // When the wait started
unsigned long waitInterval = 120000; // 2 minutes in milliseconds
float batt_per = 0;
bool Time_error_flag = 0;

void setup()
{

  Serial.begin(115200);
  Serial.println("System Initializing ");

  // LED setup
  led_setup();
 
  // Initialize i2c for Fuel Gauge & LIDAR
  init_i2c();

//Attaching interrupt for reset button
pinMode(Reset_pin, INPUT_PULLUP);
attachInterrupt(Reset_pin, isr, FALLING);

  // Check battery percentage first before initializing Wi-Fi and LIDAR sensor.
  batt_per = batteryPercentage();

  // if battery percentage is less than cut-off percentage, put the device to sleep mode and wake up again in 30mins
  if (batt_per <= LOW_BATTERY_PERCENTAGE)
  {
    Serial.printf("Battery Percentage : %d\n", batt_per);
    Serial.println(get_battery_data());
    Serial.println("DEEP Sleep due to low battery");
    battery_low_led(); // Glow RED LED
    delay(1000);

    // setup system timer for wakeup after deep sleep
    esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP_FOR_CHARGE_BATTERY * uS_TO_S_FACTOR);
    esp_deep_sleep_start(); // deep sleep mode for 60 min
  }
  else if (batt_per > MAX_PERCENTAGE)//battery data exceeding 100 (init error)
  {
 Serial.printf("Battery Percentage : %d\n", batt_per);
    Serial.println("Fuel_gauge init Error_Deep_sleep");
    error_led() ;
    delay(1000);
    //deep sleep for 30 mins
esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP_FOR_DAY * uS_TO_S_FACTOR);
     esp_deep_sleep_start();
  }
  else
{
    init_WiFi();// initializing wifi after checking battery conditions
}
}



void loop()
{

//If Reset button is pressed, Flash memory will be restored to default value.
  if(Request)
  {
    SPIFFS.remove("/userParameters.json");//deleting the config file from the flash 
    // SPIFFS_write();//parameters are empty ,triggering new onboarding.
    Request= false;//reseting the bool value.
    ESP.restart();//restarting ESP post updation.
  }
  else
  {
 unsigned long currentTime = millis();
//check if wifi is connected
 if(WiFi.status() == WL_CONNECTED)
  {
     wifi_connect_led();
     delay(1000);
    //initializing begin time to capture time 
     begin_time(WiFi_time_zone); 
     //saving the json format of the device data(Lidar,fuelgauge and time)
  String test_data = device_data();

  //HTTP req of the device data
  uint8_t serverResponse = sendData(test_data);
// clearing the data variable after posting
  test_data = "";
//creating scenerios of the server response
  switch (serverResponse)
  {
  case 0:
    Serial.println("Device Not Connected");
    break;
  case 1:
    Serial.println("Data Not Received by server");
    error_led();
    break;
  case 2:
    Serial.println("Data sent successfully");
    data_sent();
    break;
  default:
    break;
  }
   uint8_t set_sleep_time = check_day_or_night();

    /* check the time is day or night */
 if (set_sleep_time== 1)
    esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP_FOR_DAY * uS_TO_S_FACTOR); // The Controller was configured with 30 mins sleep timer
 else if (set_sleep_time == 2)
    esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP_FOR_NIGHT * uS_TO_S_FACTOR); // The Controller was configured with 60 mins sleep timer
 else  
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP_FOR_DAY * uS_TO_S_FACTOR); // deep sleep mode for 30 seconds

   led_off();
   Serial.println(" Device in Sleep Mode ");
   esp_deep_sleep_start();

  }
else if (WiFi.status() != WL_CONNECTED)
{
  wifi_disconnect_led();//LED indication
  delay(1000);
  //if WIFI_SOFT AP is connected
 if (Client_status == 1) {
    waitStart = currentTime;//reseting the timer for another 2 minutes.
 }
 else if (Client_status == 0)
 {   
      // Check if 2 minutes have passed since the waiting started
      if (currentTime - waitStart >= waitInterval) 
      {
        Serial.println("2 minutes wait time have passed");
   led_off();//turning off all LEDs prior to sleep function
   esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP_FOR_DAY * uS_TO_S_FACTOR);//device to sleep after the network failure and waiting for 2 mins
   Serial.println(" Device in Sleep Mode ");
   esp_deep_sleep_start();
 }
}
}
  }
}
