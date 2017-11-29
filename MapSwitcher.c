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
        return 0;
}
