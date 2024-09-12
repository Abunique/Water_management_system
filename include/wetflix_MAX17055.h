#ifndef wetflix_MAX17055_h
#define wetflix_MAX17055_h

#define DEBUG

#include <Arduino-MAX17055_Driver.h>

extern MAX17055 sensor;
/* initialize and deinitialzize the i2c*/
void init_i2c();
void deinit_i2c();

/* reads the battery data*/
String get_battery_data();

/*reads the battery percentage */
float batteryPercentage();

#endif