#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parseNMEA.h"

static int getNext(int pos, char *line, char *dest)
{
	char *tmp = line+pos;
	int iterator = 0;
	while(*tmp != ',' && *tmp != '*' && *tmp != '\r'){
		tmp++;
		iterator++;
	}
	tmp = line+pos;
	strncpy(dest, tmp, iterator);
	dest[iterator] = '\0';	
	return pos + iterator+1;
}

void parseGPGGA(GPGGA *in, char *strToParse)
{
	int pos = 0;
	pos = getNext(pos, strToParse, in->MessageID );
	pos = getNext(pos, strToParse, in->UTCTime );
	pos = getNext(pos, strToParse, in->Latitude );
	pos = getNext(pos, strToParse, in->NSIndicator );
	pos = getNext(pos, strToParse, in->Longitude );
	pos = getNext(pos, strToParse, in->EWIndicator );
	pos = getNext(pos, strToParse, in->PositionFixIndicator );
	pos = getNext(pos, strToParse, in->SatellitesUsed );
	pos = getNext(pos, strToParse, in->HDOP );
	pos = getNext(pos, strToParse, in->MSLAltitude );
	pos = getNext(pos, strToParse, in->MSLUnits );
	pos = getNext(pos, strToParse, in->GeoidSeparation );
	pos = getNext(pos, strToParse, in->GeoidUnits );
	pos = getNext(pos, strToParse, in->AgeOfDiffCorr );
	pos = getNext(pos, strToParse, in->DiffRefStationID );
	getNext(pos, strToParse, in->Checksum );
}
void parseGPRMC(GPRMC *in, char *strToParse)
{
	int pos = 0;
	pos = getNext(pos, strToParse, in->RMCMessageID );
	pos = getNext(pos, strToParse, in->UTCPosition );
	pos = getNext(pos, strToParse, in->Status );
	pos = getNext(pos, strToParse, in->RMCLatitude );
	pos = getNext(pos, strToParse, in->RMCNSIndicator );
	pos = getNext(pos, strToParse, in->RMCLongitude );
	pos = getNext(pos, strToParse, in->RMCEWIndicator );
	pos = getNext(pos, strToParse, in->SpeedOverGround );
	pos = getNext(pos, strToParse, in->CourseOverGround );
	pos = getNext(pos, strToParse, in->Date );
	pos = getNext(pos, strToParse, in->MagneticVariation );
	pos = getNext(pos, strToParse, in->RMCEWIndicator );
	getNext(pos, strToParse, in->Checksum );
}
