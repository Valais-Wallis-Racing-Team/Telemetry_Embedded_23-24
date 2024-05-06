/*! --------------------------------------------------------------------
 *	Telemetry System	-	@file can_controller.h
 *----------------------------------------------------------------------
 * HES-SO Valais Wallis 
 * Systems Engineering
 * Infotronics
 * ---------------------------------------------------------------------
 * @author Sylvestre van Kappel
 * @date 02.08.2023
 * ---------------------------------------------------------------------
 * @brief Can Controller task receives data from the CAN Bus and fill 
 *        the sensor buffer with the received data
 * ---------------------------------------------------------------------
 * Telemetry system for the Valais Wallis Racing Team.
 * This file contains code for the onboard device of the telemetry
 * system. The system receives the data from the sensors on the CAN bus 
 * and the data from the GPS on a UART port. An SD Card contains a 
 * configuration file with all the system parameters. The measurements 
 * are sent via Wi-Fi to a computer on the base station. The measurements 
 * are also saved in a CSV file on the SD card. 
 *--------------------------------------------------------------------*/

#ifndef __CAN_CONTROLLER_H
#define __CAN_CONTROLLER_H

/*! CAN_Controller implements the CAN_Controller task
* @brief CAN_Controller read the CAN Bus and fill the sensorBuffer array 
*        
*/
void CAN_Controller(void);

/*! Task_CAN_Controller_Init implements the CAN_Controller task initialization
* @brief CAN_Controller thread initialization
*      
*/
void Task_CAN_Controller_Init( void );

/*! canGPS_timer_handler is called by the timer interrupt
* @brief canGPS_timer_handler submit a new work that sends the data of the GPS   
*/
void canGPS_timer_handler();

/*! canGPS_timer_handler is called by the timer interrupt
* @brief canGPS_timer_handler execute the work submitted by the interrupt   
*/
void can_gps_sender();

/*! sendLat
* @brief send Latitude
*      
*/
void sendLat( uint8_t * data );

/*! sendLong
* @brief send Longitude
*      
*/
void sendLong( uint8_t * data );

/*! sendTimeFixSpeed
* @brief send Time/date Fix info and speed
*      
*/
void sendTimeFixSpeed( uint8_t * data );


#endif /*__CAN_CONTROLLER_H*/