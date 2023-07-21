#include <zephyr/kernel.h>
#include <nrfx_clock.h>

#include "task/wifi_sta.h"
#include "task/udp_client.h"
#include "task/led.h"
#include "task/data_sender.h"
#include "task/data_logger.h"
#include "task/memory_management.h"
#include "task/config_read.h"
#include "task/button_manager.h"
#include "task/can_controller.h"
#include "task/gps_controller.h"

K_HEAP_DEFINE(messageHeap,32768);
K_QUEUE_DEFINE(udpQueue);


int main(void)
{
	Task_Led_Init();		//start led controller Thread
	Task_Button_Manager_Init();		//start button manager thread
	int ret = read_config();
	if(ret == 0)			//read configuration file ok
	{
		Task_Wifi_Sta_Init();			//start wifi stationning Thread
		
		Task_UDP_Client_Init();			//start udp client Thread

		Task_GPS_Controller_Init();		//start gps controller thread

		Task_Data_Sender_Init();		// start data sender

		Task_Data_Logger_Init();		//start data logger

		Task_CAN_Controller_Init();		//start can controller thread
		
	}

	k_sleep( K_FOREVER );
	return 0;
}
