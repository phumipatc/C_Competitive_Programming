/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dis[610][610],dp[610];
int main(){
    int n,temp;
    scanf("%d",&n);
	for(int i=1;i<=2*n;i++){
		for(int j=1;j<=2*n;j++){
			dis[i][j] = 1e9;
			if(i == j)	dis[i][j] = 0;
		}
		dp[i] = 1e9;
	}
    for(int i=1;i<=2*n;i++){
        for(int j=1;j<=2*n;j++){
            scanf("%d",&temp);
            if(i<j)     continue;
            if(i == 1)  continue;
            if(j == 1)  continue;
			dis[i][j] = min(dis[i][j],temp);
        }
    }
	dp[2*n] = 0;
	for(int i=2*n;i>=1;i--){
		for(int j=i-1;j>=1;j--){
			dp[j] = min(dp[j],dp[i]+dis[i][j]);
		}
	}
	printf("%d\n",dp[2]);
	return 0;
}
/*
5
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 14 0 0 0 0 0 0 0 0
0 30 15 0 0 0 0 0 0 0
0 41 21 13 0 0 0 0 0 0
0 51 42 22 11 0 0 0 0 0
0 75 58 34 28 12 0 0 0 0
0 67 71 44 37 23 14 0 0 0
0 95 77 51 41 44 28 15 0 0
0 96 94 66 72 41 37 30 11 0
*/