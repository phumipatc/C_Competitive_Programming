/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
int r,c,nways=0,x[4]={0,0,1,-1},y[4]={1,-1,0,0},k;
int min,max;
char t[10][10];
void count(int ir,int ic,int len){
    int i,newr,newc,old;
    if(ir==r-1 && ic==c-1){
        if(len==k){
        nways++;
        }
        if(len<min) min=len;
        if(len>max) max=len;
        return;
    }
    old=t[ir][ic];
    t[ir][ic]='x';
    for(i=0;i<4;i++){
        newr=ir+x[i];
        if(newr<0 || newr>=r)   continue;
        newc=ic+y[i];
        if(newc<0 || newc>=c)   continue;
        if(t[newr][newc]!='.')  continue;
        count(newr,newc,len+1);
    }
    t[ir][ic]=old;
}
int main()
{
    int i;
    scanf("%d %d %d",&r,&c,&k);
    for(i=0;i<r;i++)
        scanf("%s",t[i]);
    min=r*c,max=0;
    count(0,0,1);
    printf("%d\n",nways);
return 0;
}
