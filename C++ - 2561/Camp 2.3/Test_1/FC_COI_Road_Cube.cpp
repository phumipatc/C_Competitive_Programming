/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[110][10010],a[110][10010];
deque<int > deq;
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int j=1;j<=m;j++)
        dp[1][j] = a[1][j];
    for(int i=2;i<=n;i++){
        for(int j=1;j<=min(k,m);j++){
            while(!deq.empty() && dp[i-1][deq.back()]<=dp[i-1][j])          deq.pop_back();
            deq.push_back(j);
        }
        for(int j=1;j<=m;j++){
            if(j+k<=m){
                while(!deq.empty() && dp[i-1][deq.back()]<=dp[i-1][j+k])    deq.pop_back();
                deq.push_back(j+k);
            }
            while(!deq.empty() && deq.front()<j-k)                          deq.pop_front();
            dp[i][j] = a[i][j]+dp[i-1][deq.front()];
            // printf("%d ",dp[i][j]);
        }
        // printf("\n");
        while(!deq.empty()) deq.pop_back();
    }
    int maxx = 0;
    for(int j=1;j<=m;j++){
        maxx = max(maxx,dp[n][j]);
    }
    printf("%d\n",maxx);
	return 0;
}
