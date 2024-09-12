#define ENABLE_FG 1
#define ENABLE_GSM_MODEM 0
#define ENABLE_GSM_NETWORK 0
#define ENABLE_WIFI_NETWORK 1
#define ENABLE_LIDAR 1
#define WIFI_MANAGER 1



// establishing esp timer variables for sending data every 30 minutes
#define uS_TO_S_FACTOR                          1000000ULL /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SLEEP_FOR_DAY                   1800        /* 30 Minutes in seconds (30 * 60) - Time ESP32 will go to sleep */ 
#define TIME_TO_SLEEP_FOR_NIGHT                 3600        /* 60 Minutes in seconds (60 * 60) - Time ESP32 will go to sleep */ 
#define TIME_TO_SLEEP_FOR_CHARGE_BATTERY        3600        /* 60 Minutes in seconds (30 * 60) - Time ESP32 will go to sleep */ 



#define WiFi_STATUS_CHECK_TIME      500/* 120 seconds(2 minutes) */



#define LOW_BATTERY_PERCENTAGE           15
#define MAX_PERCENTAGE                   100

 extern float batt_per;
 extern bool Time_error_flag;


typedef enum{
    DEVICE_NOT_CONNECTED = 0,
    DEVICE_CONNECTED = 1,
    DATA_SENT_SUCCESSFULLY = 2,
    DATA_SEND_FAILED = 3
}wetflix_device_events_t;


#define POWER_LED_PIN           33
#define RED_LED_PIN             13
#define GREEN_LED_PIN           14
#define BLUE_LED_PIN            32

