/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define HASH 5000011
using namespace std;
struct A{
    int x,y;
};
A a[4][1510];
int hashh[HASH],keep[2][HASH];
int main(){
    int xt,yt,n,r,s,ha;
    scanf("%d %d %d",&xt,&yt,&n);
    for(int i=0;i<4;i++)
        for(int j=1;j<=n;j++)
            scanf("%d %d",&a[i][j].x,&a[i][j].y);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            r = a[0][i].x+a[1][j].x,s = a[0][i].y+a[1][j].y;
            ha = (((r+((3*s)%HASH))%HASH)+HASH)%HASH;
            while(hashh[ha]){
                ha++;
                ha%=HASH;
            }
            hashh[ha] = (1500*i)+j+1;
            keep[0][ha] = r,keep[1][ha] = s;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            r = xt-(a[2][i].x+a[3][j].x),s = yt-(a[2][i].y+a[3][j].y);
            ha = (((r+((3*s)%HASH))%HASH)+HASH)%HASH;
            while(hashh[ha]){
                if(keep[0][ha] == r && keep[1][ha] == s){
                    ha = hashh[ha]-1;
                    printf("%d %d\n",a[0][ha/1500].x,a[0][ha/1500].y);
                    printf("%d %d\n",a[1][ha%1500].x,a[1][ha%1500].y);
                    printf("%d %d\n",a[2][i].x,a[2][i].y);
                    printf("%d %d\n",a[3][j].x,a[3][j].y);
                }
                ha++;
                ha%=HASH;
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