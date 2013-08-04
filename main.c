#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"buGPS.h"

int main()
{
	char *retval;
	retval = malloc(100);
	BUinitGPS(0, 100);
	sleep(2);
	while(1){
		printf("Time: %s\n", getUTCTime(retval));
		printf("Longitude: %s\n", getLongitude(retval));
	}
	return 0;
}
