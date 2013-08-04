#ifndef PARSENMEA_H
#define PARSENMEA_H

typedef struct GPGSA{
	// Todo: Add members
} GPGSA;

typedef struct GPRMC{
	char RMCMessageID[7];
	char UTCPosition[11];
	char Status[2];
	char RMCLatitude[11];
	char RMCNSIndicator[2];
	char RMCLongitude[11];
	char RMCEWIndicator[2];
	char SpeedOverGround[8];
	char CourseOverGround[6];
	char Date[7];
	char MagneticVariation[4];
	char RMCEWIndicator2[2];
	char Checksum[8];
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
	// ToDo: Add members
} GPGSV;

void parseGPGGA(GPGGA *in,char *strToParse); 
#endif
