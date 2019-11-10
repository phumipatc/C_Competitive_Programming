/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int r,c,max=0,min=1<<30,diri[]={0,0,1,-1},dirj[]={1,-1,0,0},ways=0;
char a[10][10];
void walk(int i,int j,int len){
    int nexti,nextj,old,k;
    if(i==r-1 && j==c-1){
        ways++;
        if(len>max) max=len;
        if(len<min) min=len;
        return ;
    }
    old=a[i][j];
    a[i][j]='x';
    for(k=0;k<4;k++){
        nexti=i+diri[k];
        nextj=j+dirj[k];
        if(nexti<0 || nexti>=r)   continue;
        if(nextj<0 || nextj>=c)   continue;
        if(a[nexti][nextj]!='.')  continue;
        walk(nexti,nextj,len+1);
    }
    a[i][j]=old;
}
int main()
{
    int i;
    scanf("%d %d",&r,&c);
    for(i=0;i<r;i++)
        scanf(" %s",a[i]);
    walk(0,0,1);
    printf("%d %d %d",ways,max,min);
    return 0;
}
