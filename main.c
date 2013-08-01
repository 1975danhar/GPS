#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include"readSerial.h"
#include"list.h"
#include"defines.h"
#include"parseNMEA.h"

int main()
{	
	int pt;
	char line[100];
	GPGGA *gpgga;
	gpgga = malloc(sizeof(GPGGA));
	pthread_mutex_init(&GPGGAMutex, NULL);
	pthread_t thread1;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pt = pthread_create( &thread1, &attr, readSerial, NULL);
	if (pt){
		printf("Error could not create thread!");
		exit(-1);
	}
	sleep(5);
	//pthread_join( thread1, NULL);
	while(1){

		system("clear");
		pthread_mutex_lock(&GPGGAMutex);
		strcpy(line, GPGGA_LIST->string);
		pthread_mutex_unlock(&GPGGAMutex);
		parseNMEA(gpgga, line);
		printf("Time: %s\n", gpgga->UTCTime);
		printf("MSL Altitude: %s\n", gpgga->PositionFixIndicator);
		sleep(2);
	}
	return 0;

	char out[20];
}
