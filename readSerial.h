#ifndef READSERIAL_H
#define READSERIAL_H

#define DEVICE "/dev/ttyUSB0"
#define BAUDRATE B4800
#define FALSE 0
#define TRUE 1

typedef unsigned char     uint8_t;

void *readSerial();

#endif

