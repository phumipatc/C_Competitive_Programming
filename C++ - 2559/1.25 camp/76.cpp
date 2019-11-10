/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<stdio.h>
double a[10][10],min=100000000;
int n,m,b[10][10];
void change(int i,int j,double value,int ch){
    if(ch==1){
        a[i-1][j]+=value;
        a[i-1][j-1]+=value;
        a[i-1][j+1]+=value;
        a[i][j-1]+=value;
        a[i][j+1]+=value;
        a[i+1][j-1]+=value;
        a[i+1][j]+=value;
        a[i+1][j+1]+=value;

    }else{
        a[i-1][j]-=value;
        a[i-1][j-1]-=value;
        a[i-1][j+1]-=value;
        a[i][j-1]-=value;
        a[i][j+1]-=value;
        a[i+1][j-1]-=value;
        a[i+1][j]-=value;
        a[i+1][j+1]-=value;
    }
}
void land(int state,double sum){
    int i,j;
    double temp;
    if(state==n*m){
            if(sum<min)
                min=sum;
        return ;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(b[i][j]!=1){
                b[i][j]=1;
                change(i,j,a[i][j]*0.1,1);
                land(state+1,sum+a[i][j]);
                change(i,j,a[i][j]*0.1,0);
                b[i][j]=0;
            }
        }
    }
}
int main()
{
    int i,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%lf",&a[i][j]);
        }
    }
    land(0,0);
    printf("%.2lf",min);
return 0;
}
