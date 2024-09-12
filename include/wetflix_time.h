#ifndef wetflix_time_h
#define wetflix_time_h

#include "time.h"

//for getting time

/*Configures the server to get current time.*/
void begin_time(char*);

/* Reads the current time and checks its day or night. */
uint8_t check_day_or_night();

/* Reads the current time */
unsigned long get_epoch_Time();

#endif