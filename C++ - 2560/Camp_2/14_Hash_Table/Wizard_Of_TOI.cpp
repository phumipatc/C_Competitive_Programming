/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
#define hsize 5000011
int hashh[hsize],keep[hsize][2];
int x[4][1600],y[4][1600];
int main()
{
    int xt,yt,n,i,j,xx,yy,num,p,s,r;
    scanf("%d %d %d",&xt,&yt,&n);
    for(i=0;i<4;i++)
        for(j=0;j<n;j++)
            scanf("%d %d",&x[i][j],&y[i][j]);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            xx=x[0][i]+x[1][j],yy=y[0][i]+y[1][j];
            num=((xx+(3*yy)%hsize)+hsize)%hsize;
            while(hashh[num]!=0){
                num++;
                num%=hsize;
            }
            hashh[num]=(i*1500)+j+1;
            keep[num][0]=xx,keep[num][1]=yy;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            xx=xt-(x[2][i]+x[3][j]),yy=yt-(y[2][i]+y[3][j]);
            num=((xx+(3*yy)%hsize)%hsize+hsize)%hsize;
            while(hashh[num]!=0){
                if(xx==keep[num][0] && yy==keep[num][1]){
                    p=hashh[num]-1;
                    r=p/1500,s=p%1500;
                    printf("%d %d\n%d %d\n",x[0][r],y[0][r],x[1][s],y[1][s]);
                    printf("%d %d\n%d %d\n",x[2][i],y[2][i],x[3][j],y[3][j]);
                    return 0;
                }
                num++;
                num%=hsize;
            }
        }
    }
    return 0;
}
/*
-2 2
2
1 2 -2 10
-6 -6 -1 3
-1 -2 -6 -5
5 -4 7 0
*/
