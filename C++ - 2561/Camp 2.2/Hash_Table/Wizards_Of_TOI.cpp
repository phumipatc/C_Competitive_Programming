/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define hashsize 5000011
using namespace std;
int hashh[hashsize],num[2][hashsize];
int x[4][1510],y[4][1510];
int main(){
    int xt,yt,n,temp,r,s,h;
    scanf("%d %d %d",&xt,&yt,&n);
    for(int i=0;i<4;i++)
        for(int j=0;j<n;j++)
            scanf("%d %d",&x[i][j],&y[i][j]);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            r = x[0][i]+x[1][j],s = y[0][i]+y[1][j];
            h = (((r+((3*s)%hashsize))%hashsize)+hashsize)%hashsize;
            while(hashh[h]!=0)  h = (h+1)%hashsize;
            hashh[h] = (1500*i)+j+1;
            num[0][h] = r,num[1][h] = s;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            r = xt-(x[2][i]+x[3][j]),s = yt-(y[2][i]+y[3][j]);
            h = (((r+((3*s)%hashsize))%hashsize)+hashsize)%hashsize;
            while(hashh[h]!=0){
                if(r == num[0][h] && s == num[1][h]){
                    temp = hashh[h]-1;
                    printf("%d %d\n",x[0][temp/1500],y[0][temp/1500]);
                    printf("%d %d\n",x[1][temp%1500],y[1][temp%1500]);
                    printf("%d %d\n",x[2][i],y[2][i]);
                    printf("%d %d\n",x[3][j],y[3][j]);
                }
                h = (h+1)%hashsize;
            }
        }
    }
	return 0;
}
