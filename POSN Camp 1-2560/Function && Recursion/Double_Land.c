/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
#include<math.h>
int mark[5][5];
double min=-1,b[5][5];
void change(int i,int j,int state){
    if(state==1){
        if(i+1<=3)   b[i+1][j]*=2;
        if(j+1<=3)   b[i][j+1]*=2;
        if(i-1>0)  b[i-1][j]*=2;
        if(j-1>0)  b[i][j-1]*=2;

        if(i+1<=3 && j+1<=3)    b[i+1][j+1]*=2;
        if(i+1<=3 && j-1>0)    b[i+1][j-1]*=2;
        if(i-1>0 && j+1<=3)    b[i-1][j+1]*=2;
        if(i-1>0 && j-1>0)    b[i-1][j-1]*=2;
    }else if(state==2){
        if(i+1<=3)   b[i+1][j]/=2;
        if(j+1<=3)   b[i][j+1]/=2;
        if(i-1>0)  b[i-1][j]/=2;
        if(j-1>0)  b[i][j-1]/=2;

        if(i+1<=3 && j+1<=3)    b[i+1][j+1]/=2;
        if(i+1<=3 && j-1>0)    b[i+1][j-1]/=2;
        if(i-1>0 && j+1<=3)    b[i-1][j+1]/=2;
        if(i-1>0 && j-1>0)    b[i-1][j-1]/=2;
    }
}
void buy(int state,double sum){
    int i,j;
    if(state==9){
        if(sum<min || min==-1)
            min=sum;
        return ;
    }
    for(i=1;i<=3;i++){
        for(j=1;j<=3;j++){
            if(mark[i][j]!=-1){
                mark[i][j]=-1;
                change(i,j,1);
                buy(state+1,sum+b[i][j]);
                change(i,j,2);
                mark[i][j]=0;
            }
        }
    }
}
int main()
{
    int i,j;
    for(i=1;i<=3;i++)
        for(j=1;j<=3;j++)
            scanf("%lf",&b[i][j]);
    buy(0,0);
    printf("%.2lf",min);
    return 0;
}
