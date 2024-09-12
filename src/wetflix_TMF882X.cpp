#include "wetflix_TMF882X.h"
#include "SparkFun_TMF882X_Library.h"
#include <Arduino.h>
#include "wetflix_led.h"

SparkFun_TMF882X myTMF882X;           // class was initialized with one variable 
static struct tmf882x_msg_meas_results myResults; // structure was initialized 

/**
 * 	@fn				    - init_sensor
 *
 * 	@brief			  - initializes the Lidar sensor 
 *
 *  @param[in]		- none
 *
 *  @param[in]		- none
 *
 *  @return       - returns the status of the initialization.
*/


uint8_t init_sensor()
{

  pinMode(LIDAR_EN, OUTPUT);
  digitalWrite(LIDAR_EN, HIGH);

  delay(1000);
  if (!myTMF882X.begin())
  {
    
    Serial.println("Error - The TMF882X failed to initialize - is the board connected?");
   error_led(); 
    return 1;

  }
  else
  {
    Serial.println("TMF882X started.");
    return 0;
  }
}

/**
 * 	@fn				    - get_sensor_data.
 *
 * 	@brief			  - Reads the water level data from lidar sensor. 
 *
 *  @param[in]		- none
 *
 *  @param[in]		- none
 *
 *  @return       - returns the string of Water Level 
*/

String get_sensor_data(){

  init_sensor();
  String Waterlevel ;
  
  myTMF882X.startMeasuring(myResults);
  for (int i = 0; i < myResults.num_results; ++i)
  {
    if(myResults.results[i].channel == 5)
    {
      Waterlevel= String(myResults.results[i].distance_mm); 
    }
  }
  myTMF882X.stopMeasuring();
  digitalWrite(LIDAR_EN, LOW);
  //Serial.printf("Water Level:%s",Waterlevel);
  return Waterlevel;
}

