#include "terasic_os.h"
#include <pthread.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include "CSpider.h"
#include "CSpiderLeg.h"
#include "CMotor.h"
#include "BtSppCommand.h"
#include "QueueCommand.h"
#include "PIO_LED.h"
#include "PIO_BUTTON.h"
#include "ADC.h"

int main(int argc, char *argv[]){

	printf("===== Group <X> Final Project =====\r\n");

	//####################################
	/*
    DO NOT TAKE THIS SECTION AWAY. SPIDER'S BEHAVIOR
    IS NOT AS EXPECTED WITHOUT THIS INITIALIZATION STEP
	*/
	//####################################

	CSpider spider; //Spider class
	CPIO_BUTTON BUTTON_PIO; //Button interface
	ADC adc; // Uncomment to use the ADC class for reading IR sensor
		
	printf("Spider Init & Standup\r\n");
	if (!spider.Init()){
		printf("Spilder Init failed\r\n");
	}else{
		if (!spider.Standup())
			printf("Spider Standup failed\r\n");
	}
	spider.SetSpeed(50);

	//####################################
	
	while (true) {
		
		if(BUTTON_PIO.GetBUTTON()==0x2) {
			
			//uint32_t channel = adc.GetChannel(0);
			////printf("dist: %d\n", channel);
			//while (channel < 1000) {
				spider.testing(20);
				//channel = adc.GetChannel(0);
				//printf("dist: %d\n", channel);
			//}
			spider.Reset();
		}
		
		if (BUTTON_PIO.GetBUTTON()==0x1) {
			spider.Reset();
		}
	}
	
	return 0;
}
