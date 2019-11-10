/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int qs[1000010],maxx[1000010][4],minn[1000010][4],dp[1000010][4];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&qs[i]);
        qs[i]+=qs[i-1];
    }
    for(int i=0;i<=n;i++)
        for(int j=0;j<=4;j++)
            dp[i][j] = 1e9;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            for(int k=1;k<=4;k++){
				if(dp[i][k]<min(qs[i]-qs[j-1]-minn[j-1][k-1],qs[i]-qs[j-1]-maxx[j-1][k-1]))	continue;
				if(dp[i][k]>min(qs[i]-qs[j-1]-minn[j-1][k-1],qs[i]-qs[j-1]-maxx[j-1][k-1])){
					dp[i][k] = min(qs[i]-qs[j-1]-minn[j-1][k-1],qs[i]-qs[j-1]-maxx[j-1][k-1]);
					maxx[i][k] = max(maxx[j-1][k-1],qs[i]-qs[j-1]);
					minn[i][k] = min(minn[j-1][k-1],qs[i]-qs[j-1]);
				}else{
					maxx[i][k] = max(maxx[i][k],max(maxx[j-1][k-1],qs[i]-qs[j-1]));
					minn[i][k] = min(minn[i][k],min(minn[j-1][k-1],qs[i]-qs[j-1]));
				}
            }
        }
    }
	return 0;
}