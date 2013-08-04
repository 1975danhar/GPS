#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include"readSerial.h"
#include"list.h"
#include"defines.h"
#include"parseNMEA.h"
static char *getGpgga(char *retval, int i)
{
	GPGGA gpgga;
	char line[100];
	
	pthread_mutex_lock(&GPGGAMutex);
	strcpy(line, GPGGA_LIST->string);
	pthread_mutex_unlock(&GPGGAMutex);
	parseGPGGA(&gpgga, line);
	switch (i){
		case 0:
			strcpy(retval, gpgga.MessageID);
			break;
		case 1:
			strcpy(retval, gpgga.UTCTime);
			break;
		case 2:
			strcpy(retval, gpgga.Latitude);
			break;
		case 3:
			strcpy(retval, gpgga.NSIndicator);
			break;
		case 4:
			strcpy(retval, gpgga.Longitude);
			break;
		case 5:
			strcpy(retval, gpgga.EWIndicator);
			break;
		case 6:
			strcpy(retval, gpgga.PositionFixIndicator);
			break;
		case 7:
			strcpy(retval, gpgga.SatellitesUsed);
			break;
		case 8:
			strcpy(retval, gpgga.HDOP);
			break;
		case 9:
			strcpy(retval, gpgga.MSLAltitude);
			break;
		case 10:
			strcpy(retval, gpgga.MSLUnits);
			break;
		case 11:
			strcpy(retval, gpgga.GeoidSeparation);
			break;
		case 12:
			strcpy(retval, gpgga.GeoidUnits);
			break;
		case 13:
			strcpy(retval, gpgga.AgeOfDiffCorr);
			break;
		case 14:
			strcpy(retval, gpgga.DiffRefStationID);
			break;
		case 15:
			strcpy(retval, gpgga.Checksum);
			break;
	}
	return retval;
}
static char *getGprmc(char *retval, int i)
{
	GPRMC gprmc;
	char line[100];
	pthread_mutex_lock(&GPRMCMutex);
	strcpy(line, GPRMC_LIST->string);
	pthread_mutex_unlock(&GPRMCMutex);
	parseGPRMC(&gprmc, line);
	switch(i){
		case 1:
			strcpy(retval, gprmc.RMCMessageID);
			break;
		case 2:
			strcpy(retval, gprmc.UTCPosition);
			break;
		case 3:
			strcpy(retval, gprmc.Status );
			break;
		case 4:		
			strcpy(retval, gprmc.RMCLatitude );
			break;
		case 5:
			strcpy(retval, gprmc.RMCNSIndicator );
			break;
		case 6:
			strcpy(retval, gprmc.RMCLongitude);
			break;
		case 7:
			strcpy(retval, gprmc.RMCEWIndicator);
			break;
		case 8:
			strcpy(retval, gprmc.SpeedOverGround);
			break;
		case 9:
			strcpy(retval, gprmc.CourseOverGround);
			break;
		case 10:
			strcpy(retval, gprmc.Date);
			break;
		case 11:
			strcpy(retval, MagneticVariation);
			break;
		case 12:
			strcpy(retval, RMCEWIndicator2);
			break;
		case 13:
			strcpy(retval.Checksum);
			break;
	}
	return retval;
}

// GPGGA
char *getMessageID(char *retval){return getGpgga(retval, 0);}
char *getUTCTime(char *retval){return getGpgga(retval, 1);}
char *getLatitude(char *retval){return getGpgga(retval, 2);}
char *getNSIndicator(char *retval){return getGpgga(retval, 3);}
char *getLongitude(char *retval){return getGpgga(retval, 4);}
char *getEWIndicator(char *retval){return getGpgga(retval, 5);}
char *getPositionFixIndicator(char *retval){return getGpgga(retval, 6);}
char *getSatellitesUsed(char *retval){return getGpgga(retval, 7);}
char *getHDOP(char *retval){return getGpgga(retval, 8);}
char *getMSLAltitude(char *retval){return getGpgga(retval, 9);}
char *getMSLUnits(char *retval){return getGpgga(retval, 10);}
char *getGeoidSeparation(char *retval){return getGpgga(retval, 11);}
char *getGeoidUnits(char *retval){return getGpgga(retval, 12);}
char *getAgeOfDiffCorr(char *retval){return getGpgga(retval, 13);}
char *getDiffRefStation(char *retval){return getGpgga(retval, 14);}
char *getChecksum(char *retval){return getGpgga(retval, 15);}

// GPRMC
char *get
int BUinitGPS(int flags, int numberOfObjects)
{
	int pt;
	pthread_mutex_init(&GPGSAMutex, NULL);
	pthread_mutex_init(&GPRMCMutex, NULL);
	pthread_mutex_init(&GPGGAMutex, NULL);
	pthread_mutex_init(&GPGSVMutex, NULL);

	pthread_t thread1;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pt = pthread_create(&thread1, &attr, readSerial, NULL);
	if (pt){
		printf("Error could not create thread!\n");
		exit(-1);
	}
	return pt;
}
