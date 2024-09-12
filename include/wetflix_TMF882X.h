#ifndef wetflix_TMF882X_H
#define wetflix_TMF882X_H

#include <Arduino.h>

#include "SparkFun_TMF882X_Library.h"

extern SparkFun_TMF882X myTMF882X;

#define LIDAR_EN 18      //Lidar enable pin  


/*initializes the Lidar sensor */

uint8_t init_sensor();

/*Reads the water level data from lidar sensor*/

String get_sensor_data();

#endif