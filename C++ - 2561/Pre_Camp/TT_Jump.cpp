/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[20010],jump[1010];
int main(){
    int q,a,b,c;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d",&a,&b,&c);
        for(int i=1;i<=c;i++)
            scanf("%d",&jump[i]);
        sort(jump+1,jump+c+1);
        if(a>b) swap(a,b);
        dp[a] = 0;
        for(int i=a+1;i<=b;i++){
            dp[i] = 1e9;
            for(int j=1;j<=c;j++){
                if(i-jump[j]<a) break;
                dp[i] = min(dp[i],dp[i-jump[j]]+1);
            }
        }
        if(dp[b] == 1e9)    printf("-1\n");
        else                printf("%d\n",dp[b]);
    }
	return 0;
}
