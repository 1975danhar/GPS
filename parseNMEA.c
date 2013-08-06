#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parseNMEA.h"
static char *getNext(char **line, char *dest)
{
	while(**line != ',' && **line != '*' && **line != '\r'){
	*dest = **line;
	dest++;
	(*line)++;
	}
	*dest='\0';
	(*line)++;
	return *line;
}

void parseGPGGA(GPGGA *in, char *strToParse)
{
	strToParse = getNext(&strToParse, in->MessageID );
	strToParse = getNext(&strToParse, in->UTCTime );
	strToParse = getNext(&strToParse, in->Latitude );
	strToParse = getNext(&strToParse, in->NSIndicator );
	strToParse = getNext(&strToParse, in->Longitude );
	strToParse = getNext(&strToParse, in->EWIndicator );
	strToParse = getNext(&strToParse, in->PositionFixIndicator );
	strToParse = getNext(&strToParse, in->SatellitesUsed );
	strToParse = getNext(&strToParse, in->HDOP );
	strToParse = getNext(&strToParse, in->MSLAltitude );
	strToParse = getNext(&strToParse, in->MSLUnits );
	strToParse = getNext(&strToParse, in->GeoidSeparation );
	strToParse = getNext(&strToParse, in->GeoidUnits );
	strToParse = getNext(&strToParse, in->AgeOfDiffCorr );
	strToParse = getNext(&strToParse, in->DiffRefStationID );
	getNext(&strToParse, in->Checksum );
}
void parseGPRMC(GPRMC *in, char *strToParse)
{
	strToParse = getNext(&strToParse, in->RMCMessageID );
	strToParse = getNext(&strToParse, in->UTCPosition );
	strToParse = getNext(&strToParse, in->Status );
	strToParse = getNext(&strToParse, in->RMCLatitude );
	strToParse = getNext(&strToParse, in->RMCNSIndicator );
	strToParse = getNext(&strToParse, in->RMCLongitude );
	strToParse = getNext(&strToParse, in->RMCEWIndicator );
	strToParse = getNext(&strToParse, in->SpeedOverGround );
	strToParse = getNext(&strToParse, in->CourseOverGround );
	strToParse = getNext(&strToParse, in->Date );
	strToParse = getNext(&strToParse, in->MagneticVariation );
	strToParse = getNext(&strToParse, in->RMCEWIndicator );
	getNext(&strToParse, in->Checksum );
}

