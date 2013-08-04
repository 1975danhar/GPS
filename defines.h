#ifndef DEFINES_H
#define DEFINES_H
#include<pthread.h>
Item *GPGSA_LIST;
Item *GPRMC_LIST;
Item *GPGGA_LIST;
Item *GPGSV_LIST;

pthread_mutex_t GPGSAMutex;
pthread_mutex_t GPRMCMutex;
pthread_mutex_t GPGGAMutex;
pthread_mutex_t GPGSVMutex;

int EXIT_BU;
#endif
