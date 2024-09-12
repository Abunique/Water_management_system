#include "wetflix_time.h"
#include "time.h"
#include <Arduino.h>
#include "wetflix_led.h"

char timeHour[3], timeyear[5], timeminute[3], timeday[3], timemonth[4];

struct tm timeinfo;
unsigned long epochTime; 

const char *ntpServer = "pool.ntp.org";
long gmtOffset_sec;
const int daylightOffset_sec = 0;



/**
 * 	@fn				 - begin_time
 *
 * 	@brief			 - Configures the server to get current time.
 *
 *  @param[in]		- none
 *
 *  @param[in]		- none
 *
 *  @return         - none
*/
void begin_time(char* user_input)
{
     // Split the string at the colon
  char *hour_str = strtok(user_input, ":");
  char *minute_str = strtok(NULL, ":");

  // Convert the hour and minute into integer
  int hour = atoi(hour_str);
  int minute = atoi(minute_str);

   // Calculate the GMT offset in seconds, taking into account the sign
 gmtOffset_sec = (hour * 3600) + (minute * 60);

 Serial.print("GMTOFFSET is given as: ");

 Serial.println(gmtOffset_sec);
      // init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

}

/**
 * 	@fn				    - get_epoch_Time.
 *
 * 	@brief			    - Reads the current time. 
 *
 *  @param[in]		    - none
 *
 *  @param[in]		    - none
 *
 *  @return             - returns the string current epoch time 
*/

unsigned long get_epoch_Time()
{
    time_t now;
    struct tm timeinfo;

    if (!getLocalTime(&timeinfo))
    {
    //Serial.println("Failed to obtain time");
        //  return ;
    }
    strftime(timemonth, 4, "%B", &timeinfo);
    strftime(timeday, 3, "%d", &timeinfo);
    strftime(timeyear, 5, "%Y", &timeinfo);
    strftime(timeHour, 3, "%H", &timeinfo);
    strftime(timeminute, 3, "%M", &timeinfo);
    time(&now);
    epochTime = now; 
    Serial.println(epochTime);
    return epochTime;
}

/**
 * 	@fn				    - check_day_or_night.
 *
 * 	@brief			    - Reads the current time and checks its day or night. 
 *
 *  @param[in]		    - none
 *
 *  @param[in]		    - none
 *
 *  @return             - returns one if its day else two inidicates night
*/


uint8_t check_day_or_night()
{
    time_t now;
    struct tm *ts;
    if (!getLocalTime(&timeinfo))
    {
        
    Serial.println("Failed to obtain time");

    return 0;
    }
    time(&now);
    ts = localtime(&now);
    //return vs.tm_hour;
    if(ts->tm_hour > 6 && ts->tm_hour < 18)
        return 1;
    else
        return 2;

}


