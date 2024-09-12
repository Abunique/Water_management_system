
 #include <Wire.h> // enable communication over the I2C for MAX17055 and LiDAr sensor
 #include <Arduino-MAX17055_Driver.h>
 #include "wetflix_MAX17055.h"
#include "user_defines.h"
#include "wetflix_led.h"

//creating a class for fuel gauge
MAX17055 sensor;

/**
 * 	@fn                 - init_i2c
 *
 * 	@brief			    - initializes the i2c protocol of the pins 21 or 22
 *
 *  @param[in]		    - none
 *
 *  @param[in]		    - none
 *
 *  @return             - none
*/
void init_i2c(){

    if (!Wire.begin(21, 22))    // This resets to 100kHz I2C 
    {   
        printf("I2C begin failed");
        error_led();
    }
     Wire.setClock(400000); // Sensor has max I2C freq of 400kHz
//set the MAH level of the battery in use.
     sensor.setCapacity(1000);// set the capacity of the battery (MAH)in use
}

/**
 * 	@fn                 - deinit_i2c
 *
 * 	@brief			    - deinitializes the i2c protocol. 
 *
 *  @param[in]		    - none
 *
 *  @param[in]		    - none
 *
 *  @return             - none.
*/
void deinit_i2c(){

    if (!Wire.end())    // This resets to 100kHz I2C 
    {   
        printf("I2C de initialization failed");
        
        error_led();//init error(fuel gauge)
    }

}
/**
 * 	@fn                 - get_battery_data
 *
 * 	@brief			    - Reads the battery data from Fuel gauge.
 *
 *  @param[in]		    - none
 *
 *  @param[in]		    - none
 *
 *  @return             - returns the string of battery data.
 */
String get_battery_data(){

    String battery_data = String(sensor.getSOC()) + "%";
    return battery_data;//string of battery data to be sent to the server
}

/**
 * 	@fn                 - batteryPercentage
 *
 * 	@brief			    - Reads the battery percentage from Fuel gauge.
 *
 *  @param[in]		    - none
 *
 *  @param[in]		    - none
 *
 *  @return             - returns the string of battery percentage.
 */

float batteryPercentage(){
     
    return (sensor.getSOC());// only the battery percentage for init
}