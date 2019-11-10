/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int b[10][10],c[10];
int main()
{
    char a[50];
    int i,state=1,count,j,k,l;
    scanf(" %s",a);
    for(i=0;i<42;i++){
        k=a[i]-'0';
        b[c[k]][k]=state;
        for(j=k-1;j>=1 && b[c[k]][k]==b[c[k]][j];count++,j--);
        for(j=k+1;j<=7 && b[c[k]][k]==b[c[k]][j];count++,j--);
        if(count>=4){
            printf(state=1)?"RED-%d\n":"YELLOW-%d\n",i+1);
        }
        count=1;
        for(j=c[k]-1;j>=0 && b[c[k]][k]==b[c[j]][k];count++,j--);
        for(j=c[k]+1;j<6 && b[c[k]][k]==b[c[j]][k];count++,j--);
        if(count>=4){
            printf(state=1)?"RED-%d\n":"YELLOW-%d\n",i+1);
        }
        c[k]++;
    }
return 0;
}
