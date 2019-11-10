/*
	TASK: Tug
	AUTHOR: PeaTT~
	SCHOOL: CRU
	LANG: CPP
*/
#include <bits/stdc++.h>
using namespace std;
int dp[1000100],a[1000100];
int main(){
    int n,i,last,now;
    scanf("%d %d",&n,&last);
    for(i=1;i<n;i++){
        scanf("%d",&now);
        a[i] = now-last;
        last = now;
    }
    dp[1] = a[1];
    for(i=2;i<n;i++)
        dp[i] = max(dp[i-1],dp[i-2]+a[i]);
    printf("%d\n",dp[n-1]);
    return 0;
}
