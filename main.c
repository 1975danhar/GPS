#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"buGPS.h"

int main()
{
	char *retval;
	int choise = 0;
	retval = malloc(100);
	BUinitGPS(0, 100);
	//sleep(2);
	while(1){
		printf("1. Message ID\n");
		printf("2. Time\n");
		printf("3. Latitude\n");
		printf("4. Longitude\n");
		printf("5. Number of satellites\n");
		printf("6. Date\n");
		scanf("%d", &choise);
		switch ((int)choise){
			case 1:
				printf("Message ID: %s\n", getMessageID(retval));
				break;
			case 2:
				printf("Time: %s\n", getUTCTime(retval));
				break;
			case 3:
				printf("Latitude: %s\n", getLatitude(retval));
				break;
			case 4:
				printf("Longitude: %s\n", getLongitude(retval));
				break;
			case 5:
				printf("Number of satellites: %s\n", getSatellitesUsed(retval));
				break;
			case 6:
				printf("Date: %s\n", getDate(retval));
			default: 
				break;
		}
	}
	return 0;
}
