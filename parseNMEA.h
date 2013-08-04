#ifndef PARSENMEA_H
#define PARSENMEA_H

typedef struct GPGSA{
	// ToDo: add struct members
} GPGSA;

typedef struct GPRMC{
	// ToDo: add struct members
} GPRMC;

typedef struct GPGGA{
	char MessageID[7];
	char UTCTime[11];
	char Latitude[11];
	char NSIndicator[2];
	char Longitude[11];
	char EWIndicator[2];
	char PositionFixIndicator[2];
	char SatellitesUsed[3];
	char HDOP[5];
	char MSLAltitude[4];
	char MSLUnits[2];
	char GeoidSeparation[4];
	char GeoidUnits[2];
	char AgeOfDiffCorr[8];
	char DiffRefStationID[5];
	char Checksum[8];
} GPGGA;

typedef struct GPGSV{
	// ToDo: add struct members
} GPGSV;

void parseNMEA(GPGGA *in,char *strToParse); 
#endif
