/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<bits/stdc.h>
int main()
{
    FILE *fpt1;
    fpt1=fopen("allc.h","w+");
        fprintf(fpt1,"#ifndef _ALLC_H\n");
        fprintf(fpt1,"#define _ALLC_H\n\n");

        fprintf(fpt1,"#include<_mingw.h>\n\n");

        fprintf(fpt1,"#include<stdio.h>\n");
        fprintf(fpt1,"#include<stdlib.h>\n");
        fprintf(fpt1,"#include<math.h>\n");
        fprintf(fpt1,"#include<string.h>\n");
        fprintf(fpt1,"#include<ctype.h>\n");
        fprintf(fpt1,"#endif\n");
    fclose(fpt1);
return 0;
}
