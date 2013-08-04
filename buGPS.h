#ifndef BUGPS_H
#define BUGPS_H

int BUinitGPS(int flags, int numberOfObjects);
char *getMessageID(char *retval); 
char *getUTCTime(char *retval);
char *getLatitude(char *retval);
char *getNSIndicator(char *retval);
char *getLongitude(char *retval);
char *getEWIndicator(char *retval);
char *getPositionFixIndicator(char *retval);
char *getSatellitesUsed(char *retval);
char *getHDOP(char *retval);
char *getMSLAltitude(char *retval);
char *getMSLUnits(char *retval);
char *getGeoidSeparation(char *retval);
char *getGeoidUnits(char *retval);
char *getAgeOfDiffCorr(char *retval);
char *getDiffRefStation(char *retval);
char *getChecksum(char *retval);

char *getRMCMe//------------------------------ (char *retval);
char * (char *retval);
char * (char *retval);
char * (char *retval);
char * (char *retval);
char * (char *retval);
char * (char *retval);
char * (char *retval);
char * (char *retval);
char * (char *retval);
char * (char *retval);
char * (char *retval);
#endif
