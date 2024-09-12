#ifndef wetflix_WiFi_h
#define wetflix_WiFi_h
#define DEBUG

#include <WiFi.h>
#include <HTTPClient.h>
#include <FS.h>                   //this needs to be first, or it all crashes and burns...
#include <SPIFFS.h>
#include <ArduinoJson.h>
#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>
#include "wetflix_WiFi.h"
#include <WiFiClientSecure.h>
#include <AsyncElegantOTA.h>
#include <esp_task_wdt.h> 

extern bool Client_status;
// extern HTTPClient http;
// extern WiFiClient client;

extern char WiFi_SSID[];
extern char WiFi_PWD[];
extern char WiFi_time_zone[];
extern char batt_per_spi[];

extern const char* SERVER_NAME_1;
extern const char* SERVER_NAME_2;




void SPIFFS_read();
void SPIFFS_write();
void wm_setup();
void init_WiFi();
uint8_t sendData(String);
int8_t check_wifiStatus();
String sensorData();
String device_data();
String Onboarding_req();
uint8_t send_httpData(const char*,String);

#endif

