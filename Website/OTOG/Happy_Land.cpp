/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int n,m,mark[10][10];
double a[10][10],min=-1;
void change(int i,int j,double add,int state){
    if(state==1){
        if(i-1>=1)  a[i-1][j]+=add;
        if(j-1>=1)  a[i][j-1]+=add;
        if(i+1<=n)  a[i+1][j]+=add;
        if(j+1<=m)  a[i][j+1]+=add;
        if(i-1>=1 && j-1>=1)  a[i-1][j-1]+=add;
        if(i-1>=1 && j+1<=m)  a[i-1][j+1]+=add;
        if(i+1<=n && j-1>=1)  a[i+1][j-1]+=add;
        if(i+1<=n && j+1<=m)  a[i+1][j+1]+=add;
    }else{
        if(i-1>=1)  a[i-1][j]-=add;
        if(j-1>=1)  a[i][j-1]-=add;
        if(i+1<=n)  a[i+1][j]-=add;
        if(j+1<=m)  a[i][j+1]-=add;
        if(i-1>=1 && j-1>=1)  a[i-1][j-1]-=add;
        if(i-1>=1 && j+1<=m)  a[i-1][j+1]-=add;
        if(i+1<=n && j-1>=1)  a[i+1][j-1]-=add;
        if(i+1<=n && j+1<=m)  a[i+1][j+1]-=add;
    }
}
void play(int st,double sum){
    if(st==n*m){
        if(sum<min || min==-1)
            min=sum;
        return ;
    }
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(mark[i][j]!=-1){
                mark[i][j]=-1;
                change(i,j,a[i][j]*0.1,1);
                play(st+1,sum+a[i][j]);
                change(i,j,a[i][j]*0.1,2);
                mark[i][j]=0;
            }
        }
    }
}
int main()
{
    int i,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%lf",&a[i][j]);
    play(0,0);
    printf("%.2lf\n",min);
    return 0;
}
