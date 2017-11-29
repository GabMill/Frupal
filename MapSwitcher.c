/****************************************************
  * Programmer: Gabriel Miller
  * File: MapSwitcher.c
  * Description: Takes query string from landing page and writes corresponding
  file name to Map_Name.txt
  **************************************************/

#include <stdio.h>
#include <cgi.h>
#include <string.h>
#include "Save.h"
int main()
{
        s_cgi * cgi;
        cgi = cgiInit();
        char mapQuery[31];
        strcpy(mapQuery, cgiGetValue(cgi, "map"));
        FILE * fileName = fopen("Map_Name.txt", "w");
        fputs(mapQuery, fileName);
        fclose(fileName);
        resetMap();
        return 0;
}
