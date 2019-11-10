/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int table[300][300],mic[300][300],mic2[300][300];
int main()
{
    int h,w,i,j;
    scanf("%d %d",&h,&w);
    for(i=1;i<=h;i++){
        for(j=1;j<=w;j++){
            scanf("%d",&table[i][j]);
        }
    }
    for(i=h;i>0;i--)
        mic[i][1]=mic2[i][1]=table[i][1]+mic[i+1][1];
    for(j=1;j<=w;j++)
        mic[h][j]=mic2[h][j]=table[h][j]+mic[h][j-1];
    for(i=h-1;i>0;i--){
        for(j=2;j<=w;j++){
            mic[i][j]=max(mic[i+1][j],mic[i][j-1])+table[i][j];
            mic2[i][j]=min(mic2[i+1][j],mic2[i][j-1])+table[i][j];
        }
    }
    printf("%d",mic[1][w]-mic2[1][w]);
    return 0;
}
