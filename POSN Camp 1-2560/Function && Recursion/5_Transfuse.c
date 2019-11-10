/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include <stdio.h>
#include <string.h>
int r, c, nways = 0, dirr[4] = {0, 0, 1, -1}, dirc[4] = {1, -1, 0, 0};
int min,max;
char table[10][10];
void count(int ir,int ic,int len) {
    int i, newr, newc, old;
    if (ir == r-1 && ic == c-1 ) {
		nways++;
		if(len<min)	min=len;
		if(len>max)	max=len;
        return ;
    }
    old = table[ir][ic];
    table[ir][ic] = 'x';
    for (i = 0; i < 4; i++) {
        newr = ir + dirr[i];
        if (newr < 0 || newr >= r) continue;
        newc = ic + dirc[i];
        if (newc < 0 || newc >= c) continue;
        if (table[newr][newc] != '.')
            continue;
        count(newr, newc, len+1);
    }
    table[ir][ic] = old;
}
int main () {
	int i;
    scanf ("%d %d", &r, &c);
    for (i = 0; i < r; i++)
        scanf ("%s", table[i]);
	min=r*c,max=0;
    count(0, 0, 1);
    printf ("%d %d %d\n", nways,max,min);
    return 0;
}
