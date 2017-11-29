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

  // Spider class
  CSpider spider;

	printf("Spider Init & Standup\r\n");
	if (!spider.Init()){
		printf("Spilder Init failed\r\n");
	}else{
		if (!spider.Standup())
			printf("Spider Standup failed\r\n");
	}
	spider.SetSpeed(50);

  //####################################

  // Uncomment to use the ADC class for reading IR sensor
	ADC adc;
	/* while (1) {
		usleep(100000);
		printf("dist: %d\n", adc.GetChannel(0));
	} */
	uint32_t channel = 0;
	channel = adc.GetChannel(0);
	printf("dist: %d\n", channel);
	while (channel < 1200) {
		spider.MoveForward(1);
		//spider.Reset();
		channel = adc.GetChannel(0);
		printf("dist: %d\n", channel);
		//usleep(1000000);
	}
	spider.Reset();
	spider.BodyUpDown(1);
	spider.Reset();
	return 0;
}
