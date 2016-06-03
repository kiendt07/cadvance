#ifndef SOUNDEX_H
#define SOUNDEX_H

#define MAX_SDEX_CTLG_LEN 10000 // max length of SoundEx catalogue
#define SOUNDEX_BTREE "SOUNDEX"

char * soundex(char *chAlphaName, char *strResult); //chAlphaName: xau nguon; ham tra ve soundex code cua chAlphaName
int init_soundex(void); //soundex's btree file: in ; dict's file: FOLDOC

#endif