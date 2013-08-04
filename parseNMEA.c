#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parseNMEA.h"

static int getNext(int pos, char *line, char *dest)
{
	char *tmp = line+pos;
	int iterator = 0;
	while(*tmp != ',' && *tmp != '*' && *tmp != '\r')
	{
		tmp++;
		iterator++;
	}
	tmp = line+pos;
	strncpy(dest, tmp, iterator);
	
	return pos + iterator+1;
}
void parseNMEA(GPGGA *in, char *strToParse)
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
