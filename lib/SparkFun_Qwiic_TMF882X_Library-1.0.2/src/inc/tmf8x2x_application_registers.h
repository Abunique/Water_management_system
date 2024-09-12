// This file has not only been generated automatically, it has also been patched automatically on top of that: All addresses have been multiplied by 4 to match the AMBA bus addressing


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!         THIS FILE IS AUTOMATICALLY GENERATED         !!
// !!              DO NOT EDIT THIS FILE                   !!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#ifndef TMF8X2X_APPLICATION_REGISTERS_H
#define TMF8X2X_APPLICATION_REGISTERS_H

#define TMF8X2X_COM_APP_ID 0x0
#define TMF8X2X_COM_APP_ID__appid__MASK  0xff
#define TMF8X2X_COM_APP_ID__appid__WIDTH 8
#define TMF8X2X_COM_APP_ID__appid__SHIFT 0
#define TMF8X2X_COM_APP_ID__appid__RESET 2
// Enumeration for appid
#define TMF8X2X_COM_APP_ID__appid__BOOTLOADER 128 // bootloader application ID 			
#define TMF8X2X_COM_APP_ID__appid__APPLICATION 2 // ROM application ID for version 2 		


#define TMF8X2X_COM_MINOR 0x1
#define TMF8X2X_COM_MINOR__minor__MASK  0xff
#define TMF8X2X_COM_MINOR__minor__WIDTH 8
#define TMF8X2X_COM_MINOR__minor__SHIFT 0
#define TMF8X2X_COM_MINOR__minor__RESET 0

#define TMF8X2X_COM_PATCH 0x2
#define TMF8X2X_COM_PATCH__patch__MASK  0xff
#define TMF8X2X_COM_PATCH__patch__WIDTH 8
#define TMF8X2X_COM_PATCH__patch__SHIFT 0
#define TMF8X2X_COM_PATCH__patch__RESET 0

#define TMF8X2X_COM_BUILD_TYPE 0x3
#define TMF8X2X_COM_BUILD_TYPE__build__MASK  0xff
#define TMF8X2X_COM_BUILD_TYPE__build__WIDTH 8
#define TMF8X2X_COM_BUILD_TYPE__build__SHIFT 0
#define TMF8X2X_COM_BUILD_TYPE__build__RESET 0

#define TMF8X2X_COM_APPLICATION_STATUS 0x4
#define TMF8X2X_COM_APPLICATION_STATUS__app_status__MASK  0xff
#define TMF8X2X_COM_APPLICATION_STATUS__app_status__WIDTH 8
#define TMF8X2X_COM_APPLICATION_STATUS__app_status__SHIFT 0
#define TMF8X2X_COM_APPLICATION_STATUS__app_status__RESET 0
// Enumeration for app_status
#define TMF8X2X_COM_APPLICATION_STATUS__app_status__SUCCESS 0 // application has no error 
#define TMF8X2X_COM_APPLICATION_STATUS__app_status__ERR_BIST 1 // histogram RAM BIST returned more than 1 error in at least 1 TDC RAM. I.e. it cannot be repaired 
#define TMF8X2X_COM_APPLICATION_STATUS__app_status__ERR_APP_CANT_STOP_MEASURE 2 // the application could not terminate the measurment statemachine. A hard shut-down of the measurement state machine was done 
#define TMF8X2X_COM_APPLICATION_STATUS__app_status__ERR_APP_TIMER_OUT_OF_RANGE 3 // upon wakeup from timed sleep the timer value was out of range. Internal program error (maybe RAM lost content).  
#define TMF8X2X_COM_APPLICATION_STATUS__app_status__ERR_UNEXPECTED_RESET 4 // host triggered a CPU reset or a piece of SW did call SystemReset 
#define TMF8X2X_COM_APPLICATION_STATUS__app_status__WARNING_NO_FUSES_FOUND 5 // fuses have not been programmed 
#define TMF8X2X_COM_APPLICATION_STATUS__app_status__ERR_CFG_NOT_ALLOWED 6 // this device type does not allow time-multiplexed configuration 
#define TMF8X2X_COM_APPLICATION_STATUS__app_status__ERR_CFG_OUT_OF_RANGE 7 // xSize, ySize is either too big or too small 
#define TMF8X2X_COM_APPLICATION_STATUS__app_status__ERR_CFG_NO_ADJACENT_SPAD 8 // not 2 adjacent SPAD in each zone (x+1


#define TMF8X2X_COM_MEASURE_STATUS 0x5
#define TMF8X2X_COM_MEASURE_STATUS__measure_status__MASK  0xff
#define TMF8X2X_COM_MEASURE_STATUS__measure_status__WIDTH 8
#define TMF8X2X_COM_MEASURE_STATUS__measure_status__SHIFT 0
#define TMF8X2X_COM_MEASURE_STATUS__measure_status__RESET 0
// Enumeration for measure_status
#define TMF8X2X_COM_MEASURE_STATUS__measure_status__SUCCESS 0 // measurement state machine has no error 
#define TMF8X2X_COM_MEASURE_STATUS__measure_status__ERR_MEASURE_VCSEL 17 // VCSEL eye safety failed 
#define TMF8X2X_COM_MEASURE_STATUS__measure_status__ERR_MEASURE_BDV 18 // failed to find a breakdown voltage 
#define TMF8X2X_COM_MEASURE_STATUS__measure_status__ERR_MEASURE_CFG_BUFFER 19 // (deprecated) no free buffer for measurement state machine 
#define TMF8X2X_COM_MEASURE_STATUS__measure_status__ERR_MEASURE_CFG_STATE 20 // (deprecated) measurement statemachine in illegal state 
#define TMF8X2X_COM_MEASURE_STATUS__measure_status__ERR_MEASURE_CFG_TOO_MANY 21 // tried to set a thrid configuration 
#define TMF8X2X_COM_MEASURE_STATUS__measure_status__ERR_MEASURE_NOT_STARTED 22 // tried to start a measurement before configuring the state machine 
#define TMF8X2X_COM_MEASURE_STATUS__measure_status__ERR_MEASURE_BUFFER_RETURN 23 // tried to return a buffer twice to the state machine 


#define TMF8X2X_COM_ALGORITHM_STATUS 0x6
#define TMF8X2X_COM_ALGORITHM_STATUS__alg_status__MASK  0xff
#define TMF8X2X_COM_ALGORITHM_STATUS__alg_status__WIDTH 8
#define TMF8X2X_COM_ALGORITHM_STATUS__alg_status__SHIFT 0
#define TMF8X2X_COM_ALGORITHM_STATUS__alg_status__RESET 0
// Enumeration for alg_status
#define TMF8X2X_COM_ALGORITHM_STATUS__alg_status__SUCCESS 0 // algorithm has no error 
#define TMF8X2X_COM_ALGORITHM_STATUS__alg_status__ERR_ALGORITHM_EC_FAILED 33 // algorithm could not perform electrical calibration (e.g. no two peeks found) 
#define TMF8X2X_COM_ALGORITHM_STATUS__alg_status__ERR_ALGORITHM_EC_BUFFER_ERROR 34 // ec function was called, but no buffer was provided 
#define TMF8X2X_COM_ALGORITHM_STATUS__alg_status__ERR_ALGORITHM_EC_CFG_MISMATCH_ERROR 35 // ec function got mismatched config index 
#define TMF8X2X_COM_ALGORITHM_STATUS__alg_status__ERR_ALGORITHM_NO_REFERENCE_PEAK 36 // no peak found in reference channel 


#define TMF8X2X_COM_FACTORY_CALIBRATION_STATUS 0x7
#define TMF8X2X_COM_FACTORY_CALIBRATION_STATUS__fc_status__MASK  0xff
#define TMF8X2X_COM_FACTORY_CALIBRATION_STATUS__fc_status__WIDTH 8
#define TMF8X2X_COM_FACTORY_CALIBRATION_STATUS__fc_status__SHIFT 0
#define TMF8X2X_COM_FACTORY_CALIBRATION_STATUS__fc_status__RESET 0
// Enumeration for fc_status
#define TMF8X2X_COM_FACTORY_CALIBRATION_STATUS__fc_status__SUCCESS 0 // factory calibration data available and matches selected SPAD mask 
#define TMF8X2X_COM_FACTORY_CALIBRATION_STATUS__fc_status__WARNING_NO_FACTORY_CALIBRATION 49 // no factory calibration available, device performance may be degraded 
#define TMF8X2X_COM_FACTORY_CALIBRATION_STATUS__fc_status__WARNING_FACTORY_CALIBRATION_DOES_NOT_MATCH_SPAD_MASK 50 // factory calibration and SPAD mask do not correlate, device performance may be degraded 


#define TMF8X2X_COM_CMD_STAT 0x8
#define TMF8X2X_COM_CMD_STAT__cmd_stat__MASK  0xff
#define TMF8X2X_COM_CMD_STAT__cmd_stat__WIDTH 8
#define TMF8X2X_COM_CMD_STAT__cmd_stat__SHIFT 0
#define TMF8X2X_COM_CMD_STAT__cmd_stat__RESET 0
// Enumeration for cmd_stat
#define TMF8X2X_COM_CMD_STAT__cmd_stat__CMD_MEASURE 16 // Measure: start a cyclic measurement according to the configuration														
#define TMF8X2X_COM_CMD_STAT__cmd_stat__CMD_CLEAR_STATUS 17 // Clear Status: clear all status registers (note that a new measurement clears them too)									
#define TMF8X2X_COM_CMD_STAT__cmd_stat__CMD_GPIO 18 // GPIO: configure GPIO pins accoring to the configuration																	
#define TMF8X2X_COM_CMD_STAT__cmd_stat__CMD_RESERVED_EC 19 // Reserved, do not use																										
#define TMF8X2X_COM_CMD_STAT__cmd_stat__CMD_RESERVED_AH 20 // Reserved, do not use																										
#define TMF8X2X_COM_CMD_STAT__cmd_stat__CMD_WRITE_CONFIG_PAGE 21 // Write Configuration page (whatever page has been loaded to registers 0x20 and following will be written to the device)	
#define TMF8X2X_COM_CMD_STAT__cmd_stat__CMD_LOAD_CONFIG_PAGE_COMMON 22 // Load Configuration Page 0 - common configuration																			
#define TMF8X2X_COM_CMD_STAT__cmd_stat__CMD_LOAD_CONFIG_PAGE_SPAD_1 23 // Load Configuration Page 1 - SPAD configuration 																			
#define TMF8X2X_COM_CMD_STAT__cmd_stat__CMD_LOAD_CONFIG_PAGE_SPAD_2 24 // Load Configuration Page 2 - SPAD configuration alternate measurement														
#define TMF8X2X_COM_CMD_STAT__cmd_stat__CMD_LOAD_CONFIG_PAGE_FACTORY_CALIB 25 // Load Configuration Page 3 - factory calibration													 
#define TMF8X2X_COM_CMD_STAT__cmd_stat__CMD_LOAD_CONFIG_PAGE_DIAGNOSTICS 26 // Load Configuration Page 4 - diagnostic configuration																		
#define TMF8X2X_COM_CMD_STAT__cmd_stat__CMD_FACTORY_CALIBRATION 32 // Perform Factory Calibration 																								
/* Only in 8x8 mode we need to manually reset the calibration */
#define TMF8X2X_COM_CMD_STAT__cmd_stat__CMD_RESET_FACTORY_CALIBRATION       (TMF8X2X_COM_CMD_STAT__cmd_stat__CMD_FACTORY_CALIBRATION-1)
#define TMF8X2X_COM_CMD_STAT__cmd_stat__CMD_I2C_SLAVE_ADDRESS 33 // Command that sets the device's I2C slave address to the address specified in config page common 					
#define TMF8X2X_COM_CMD_STAT__cmd_stat__CMD_BREAKPOINT_GO 50 // Breakpoint Go: after an enabled brakpoint has been hit, the host needs to send this command to have execution go on		
#define TMF8X2X_COM_CMD_STAT__cmd_stat__CMD_SWITCH_TMF8828_MODE 108 // Switch to 8x8 mode (if HW supports it)
#define TMF8X2X_COM_CMD_STAT__cmd_stat__CMD_SWITCH_TMF8821_MODE 101 // Switch to 3x3/4x4 mode
#define TMF8X2X_COM_CMD_STAT__cmd_stat__CMD_RESET 254 // Reset: a software system reset shall be executed																			
#define TMF8X2X_COM_CMD_STAT__cmd_stat__CMD_STOP 255 // Stop: abort any ongoing measurement																						
#define TMF8X2X_COM_CMD_STAT__cmd_stat__STAT_OK 0 // Ok, command accepted and successfully executed 																									
#define TMF8X2X_COM_CMD_STAT__cmd_stat__STAT_ACCEPTED 1 // Command accepted and being executed, must send a STOP command to halt continues execution															
#define TMF8X2X_COM_CMD_STAT__cmd_stat__STAT_ERR_CONFIG 2 // ERROR configuration not accepted, ready to accept new command 																					
#define TMF8X2X_COM_CMD_STAT__cmd_stat__STAT_ERR_APPLICATION 3 // ERROR application encountered a severe error and stopped (more details see register TMF8X2X_COM_APPLICATION_STATUS), ready to accept new command 	
#define TMF8X2X_COM_CMD_STAT__cmd_stat__STAT_ERR_WAKEUP_TIMED 4 // ERROR wakeup timed, severe internal error, device should be power cycled 																			
#define TMF8X2X_COM_CMD_STAT__cmd_stat__STAT_ERR_RESET_UNEXPECTED 5 // ERROR unexpected reset, severe internal error, device should be power cycles 																		
#define TMF8X2X_COM_CMD_STAT__cmd_stat__STAT_ERR_UNKNOWN_CMD 6 // ERROR unknown command                                               																			    
#define TMF8X2X_COM_CMD_STAT__cmd_stat__STAT_ERR_NO_REF_SPAD 7 // ERROR after screamer masking no reference SPAD is selected anymore, change your enable mask 														
#define TMF8X2X_COM_CMD_STAT__cmd_stat__STAT_ERR_NO_FLICKER_SPAD 8 // ERROR after screamer masking no flicker SPAD is selected anymore, change your enable mask															
#define TMF8X2X_COM_CMD_STAT__cmd_stat__STAT_ERR_UNKNOWN_CID 9 // ERROR tried to write a config page with unknown CID, ready to accept new command 																	
#define TMF8X2X_COM_CMD_STAT__cmd_stat__STAT_WARNING_CONFIG_SPAD_1_NOT_ACCEPTED 10 // WARNING writing of config SPAD 1 page was ignored, as pre-selected SPAD mask is configured in common page 										
#define TMF8X2X_COM_CMD_STAT__cmd_stat__STAT_WARNING_CONFIG_SPAD_2_NOT_ACCEPTED 11 // WARNING writing of config SPAD 2 page was ignored, as pre-selected SPAD mask, or single user defined is configured in common page 				
#define TMF8X2X_COM_CMD_STAT__cmd_stat__STAT_WARNING_OSC_TRIM_NOT_ACCEPTED 12 // WARNING new osc trim value was ignored, as allow_osc_retrim was not set in register TMF8X2X_COM_POWER_CONFIG 										
#define TMF8X2X_COM_CMD_STAT__cmd_stat__STAT_WARNING_I2C_ADDRESS_NOT_ACCEPTED 13 // WARNING did not accept new I2C address, as GPIOs did not match switching condition 																
#define TMF8X2X_COM_CMD_STAT__cmd_stat__STAT_ERR_UNKNOWN_MODE 14 // ERROR this mode is not supported, read to accept a new command  																


#define TMF8X2X_COM_PREV_CMD 0x9
#define TMF8X2X_COM_PREV_CMD__prev_cmd__MASK  0xff
#define TMF8X2X_COM_PREV_CMD__prev_cmd__WIDTH 8
#define TMF8X2X_COM_PREV_CMD__prev_cmd__SHIFT 0
#define TMF8X2X_COM_PREV_CMD__prev_cmd__RESET 0

#define TMF8X2X_COM_LIVE_BEAT 0xa
#define TMF8X2X_COM_LIVE_BEAT__live_beat__MASK  0xff
#define TMF8X2X_COM_LIVE_BEAT__live_beat__WIDTH 8
#define TMF8X2X_COM_LIVE_BEAT__live_beat__SHIFT 0
#define TMF8X2X_COM_LIVE_BEAT__live_beat__RESET 0

#define TMF8X2X_COM_LIVE_GPIO 0xb
#define TMF8X2X_COM_LIVE_GPIO__live_gpio0__MASK  0x1
#define TMF8X2X_COM_LIVE_GPIO__live_gpio0__WIDTH 1
#define TMF8X2X_COM_LIVE_GPIO__live_gpio0__SHIFT 0
#define TMF8X2X_COM_LIVE_GPIO__live_gpio0__RESET 0
#define TMF8X2X_COM_LIVE_GPIO__live_gpio0 1
#define TMF8X2X_COM_LIVE_GPIO__live_gpio1__MASK  0x2
#define TMF8X2X_COM_LIVE_GPIO__live_gpio1__WIDTH 1
#define TMF8X2X_COM_LIVE_GPIO__live_gpio1__SHIFT 1
#define TMF8X2X_COM_LIVE_GPIO__live_gpio1__RESET 0
#define TMF8X2X_COM_LIVE_GPIO__live_gpio1 2

#define TMF8X2X_COM_APPLICATION_STATE 0xc
#define TMF8X2X_COM_APPLICATION_STATE__live_app_state__MASK  0xff
#define TMF8X2X_COM_APPLICATION_STATE__live_app_state__WIDTH 8
#define TMF8X2X_COM_APPLICATION_STATE__live_app_state__SHIFT 0
#define TMF8X2X_COM_APPLICATION_STATE__live_app_state__RESET 0

#define TMF8X2X_COM_MEASURE_STATE 0xd
#define TMF8X2X_COM_MEASURE_STATE__live_measure_state__MASK  0xff
#define TMF8X2X_COM_MEASURE_STATE__live_measure_state__WIDTH 8
#define TMF8X2X_COM_MEASURE_STATE__live_measure_state__SHIFT 0
#define TMF8X2X_COM_MEASURE_STATE__live_measure_state__RESET 0

#define TMF8X2X_COM_ALGORITHM_STATE 0xe
#define TMF8X2X_COM_ALGORITHM_STATE__live_alg_state__MASK  0xff
#define TMF8X2X_COM_ALGORITHM_STATE__live_alg_state__WIDTH 8
#define TMF8X2X_COM_ALGORITHM_STATE__live_alg_state__SHIFT 0
#define TMF8X2X_COM_ALGORITHM_STATE__live_alg_state__RESET 0

#define TMF8X2X_COM_FACTORY_CALIBRATION_STATE 0xf
#define TMF8X2X_COM_FACTORY_CALIBRATION_STATE__live_factory_calibration_state__MASK  0xff
#define TMF8X2X_COM_FACTORY_CALIBRATION_STATE__live_factory_calibration_state__WIDTH 8
#define TMF8X2X_COM_FACTORY_CALIBRATION_STATE__live_factory_calibration_state__SHIFT 0
#define TMF8X2X_COM_FACTORY_CALIBRATION_STATE__live_factory_calibration_state__RESET 0

#define TMF8X2X_COM_MODE 0x10
#define TMF8X2X_COM_MODE__mode__MASK  0x08
#define TMF8X2X_COM_MODE__mode__WIDTH 1
#define TMF8X2X_COM_MODE__mode__SHIFT 3
#define TMF8X2X_COM_MODE__mode__RESET 0

#define TMF8X2X_COM_BDV_VALUE 0x1b
#define TMF8X2X_COM_BDV_VALUE__bdv_value__MASK  0xff
#define TMF8X2X_COM_BDV_VALUE__bdv_value__WIDTH 8
#define TMF8X2X_COM_BDV_VALUE__bdv_value__SHIFT 0
#define TMF8X2X_COM_BDV_VALUE__bdv_value__RESET 0

#define TMF8X2X_COM_SERIAL_NUMBER_0 0x1c
#define TMF8X2X_COM_SERIAL_NUMBER_0__serial_number_7_0__MASK  0xff
#define TMF8X2X_COM_SERIAL_NUMBER_0__serial_number_7_0__WIDTH 8
#define TMF8X2X_COM_SERIAL_NUMBER_0__serial_number_7_0__SHIFT 0
#define TMF8X2X_COM_SERIAL_NUMBER_0__serial_number_7_0__RESET 0

#define TMF8X2X_COM_SERIAL_NUMBER_1 0x1d
#define TMF8X2X_COM_SERIAL_NUMBER_1__serial_number_15_8__MASK  0xff
#define TMF8X2X_COM_SERIAL_NUMBER_1__serial_number_15_8__WIDTH 8
#define TMF8X2X_COM_SERIAL_NUMBER_1__serial_number_15_8__SHIFT 0
#define TMF8X2X_COM_SERIAL_NUMBER_1__serial_number_15_8__RESET 0

#define TMF8X2X_COM_SERIAL_NUMBER_2 0x1e
#define TMF8X2X_COM_SERIAL_NUMBER_2__serial_number_23_16__MASK  0xff
#define TMF8X2X_COM_SERIAL_NUMBER_2__serial_number_23_16__WIDTH 8
#define TMF8X2X_COM_SERIAL_NUMBER_2__serial_number_23_16__SHIFT 0
#define TMF8X2X_COM_SERIAL_NUMBER_2__serial_number_23_16__RESET 0

#define TMF8X2X_COM_SERIAL_NUMBER_3 0x1f
#define TMF8X2X_COM_SERIAL_NUMBER_3__serial_number_31_24__MASK  0xff
#define TMF8X2X_COM_SERIAL_NUMBER_3__serial_number_31_24__WIDTH 8
#define TMF8X2X_COM_SERIAL_NUMBER_3__serial_number_31_24__SHIFT 0
#define TMF8X2X_COM_SERIAL_NUMBER_3__serial_number_31_24__RESET 0

#define TMF8X2X_COM_CONFIG_RESULT 0x20
#define TMF8X2X_COM_CONFIG_RESULT__cid_rid__MASK  0xff
#define TMF8X2X_COM_CONFIG_RESULT__cid_rid__WIDTH 8
#define TMF8X2X_COM_CONFIG_RESULT__cid_rid__SHIFT 0
#define TMF8X2X_COM_CONFIG_RESULT__cid_rid__RESET 0
// Enumeration for cid_rid
#define TMF8X2X_COM_CONFIG_RESULT__cid_rid__COMMON_CID 22 // COMMON configuration page 											 	
#define TMF8X2X_COM_CONFIG_RESULT__cid_rid__SPAD_1_CID 23 // SPAD configuration page 1 (first measurement in time multiplexed mode) 	
#define TMF8X2X_COM_CONFIG_RESULT__cid_rid__SPAD_2_CID 24 // SPAD configuration page 2 (2nd measurement in time multiplexed mode)	 	
#define TMF8X2X_COM_CONFIG_RESULT__cid_rid__FACTORY_CALIBRATION_CID 25 // factory calibration page ID 												
#define TMF8X2X_COM_CONFIG_RESULT__cid_rid__DIAGNOSTICS_CID 26 // diagnostics page ID         												
#define TMF8X2X_COM_CONFIG_RESULT__cid_rid__MEASUREMENT_RESULT 16 // result record of a measurement 											
#define TMF8X2X_COM_CONFIG_RESULT__cid_rid__ELECTRICAL_CALIBRATION_RESULT 19 // electrical calibration result  										
#define TMF8X2X_COM_CONFIG_RESULT__cid_rid__ACCUMULATED_HITS_RESULT 20 // statistical information about a measurement 								


#define TMF8X2X_COM_TID 0x21
#define TMF8X2X_COM_TID__tid__MASK  0xff
#define TMF8X2X_COM_TID__tid__WIDTH 8
#define TMF8X2X_COM_TID__tid__SHIFT 0
#define TMF8X2X_COM_TID__tid__RESET 0

#define TMF8X2X_COM_SIZE_LSB 0x22
#define TMF8X2X_COM_SIZE_LSB__size_7_0__MASK  0xff
#define TMF8X2X_COM_SIZE_LSB__size_7_0__WIDTH 8
#define TMF8X2X_COM_SIZE_LSB__size_7_0__SHIFT 0
#define TMF8X2X_COM_SIZE_LSB__size_7_0__RESET 0

#define TMF8X2X_COM_SIZE_MSB 0x23
#define TMF8X2X_COM_SIZE_MSB__size_15_8__MASK  0xff
#define TMF8X2X_COM_SIZE_MSB__size_15_8__WIDTH 8
#define TMF8X2X_COM_SIZE_MSB__size_15_8__SHIFT 0
#define TMF8X2X_COM_SIZE_MSB__size_15_8__RESET 0

#endif // TMF8X2X_APPLICATION_REGISTERS_H
