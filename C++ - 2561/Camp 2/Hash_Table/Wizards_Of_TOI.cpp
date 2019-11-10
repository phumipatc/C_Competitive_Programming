/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define HS 5000011
using namespace std;
int hashh[HS],keep[2][HS],xt,yt,n,p,r,s,t;
int x[4][1510],y[4][1510];
int main(){
    scanf("%d %d %d",&xt,&yt,&n);
    for(int i=0;i<4;i++)
        for(int j=0;j<n;j++)
            scanf("%d %d",&x[i][j],&y[i][j]);
    //Earth & Water
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            r = x[0][i]+x[1][j],s = y[0][i]+y[1][j];
            t = (((r+((3*s)%HS))%HS)+HS)%HS;
            while(hashh[t]!=0)  t = (t+1)%HS;
            hashh[t] = (1500*i)+j+1;
            keep[0][t] = r,keep[1][t] = s;
        }
    }
    //Wind & Fire
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            r = xt-(x[2][i]+x[3][j]),s = yt-(y[2][i]+y[3][j]);
            t = (((r+((3*s)%HS))%HS)+HS)%HS;
            while(hashh[t]!=0){
                if(r == keep[0][t] && s == keep[1][t]){
                    p = hashh[t]-1;
                    printf("%d %d\n",x[0][p/1500],y[0][p/1500]);
                    printf("%d %d\n",x[1][p%1500],y[1][p%1500]);
                    printf("%d %d\n",x[2][i],y[2][i]);
                    printf("%d %d\n",x[3][j],y[3][j]);
                }
                t = (t+1)%HS;
            }
        }
    }
	return 0;
}
