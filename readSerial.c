#include"readSerial.h"
#include"list.h"
#include"defines.h"
#include<stdio.h>
#include<termios.h>
#include<fcntl.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>
#include<sys/types.h>
#include<stropts.h>

static int nmea_checksum(char *line)
{
	uint8_t checksum = 0;
	while (*line){
		if (*line == '$'){
			line++;
			continue;
		}
		if (*line == '*')
			break;
		checksum ^= *line++;
	}
	return (strtoul(line+1, NULL, 16) == checksum);
}
void *readSerial()
{
	int STOP=FALSE;
	int fd, res;
	char line[82];
	struct termios attrib;

	fd = open(DEVICE, O_RDONLY);
	if(fd == -1){
		printf("Could not open %s, errno = %d", DEVICE, errno);
		exit(1);
	}
	attrib.c_lflag = ICANON;
	attrib.c_iflag = IXOFF | IUTF8;
	attrib.c_cflag = BAUDRATE | CRTSCTS | CS8 | CLOCAL | CREAD;
	tcflush(fd, TCIFLUSH);
	if(tcsetattr(fd, TCSANOW, &attrib) == -1){
		printf("Could not set attributes!\n");
		exit(1);
	}

	while (STOP==FALSE){
		res = read( fd, line, 81);
		line[res]=0;
		if(nmea_checksum(line)){
			if(strstr(line, "$GPGGA")!=NULL){
				pthread_mutex_lock(&GPGGAMutex);
				GPGGA_LIST = pushItem(GPGGA_LIST, line);
				pthread_mutex_unlock(&GPGGAMutex);
			}
			if(strstr(line, "$GPGSA")!=NULL){
				pthread_mutex_lock(&GPGSAMutex);
				GPGSA_LIST = pushItem(GPGSA_LIST, line);
				pthread_mutex_unlock(&GPGSAMutex);
			}
			if(strstr(line, "$GPRMC")!=NULL){
				pthread_mutex_lock(&GPRMCMutex);
				GPRMC_LIST = pushItem(GPRMC_LIST, line);
				pthread_mutex_unlock(&GPRMCMutex);
			}
			if(strstr(line, "$GPGSV")!=NULL){
				pthread_mutex_lock(&GPGSVMutex);
				GPGSV_LIST = pushItem(GPGSV_LIST, line);
				pthread_mutex_unlock(&GPGSVMutex);
			}
		}
	} 
 	close(fd);
	return NULL;
}
