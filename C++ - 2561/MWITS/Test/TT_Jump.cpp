/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[20010],jump[1010];
int main(){
    int q,a,b,c,temp;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d",&a,&b,&c);
        if(a>b) swap(a,b);
        for(int i=0;i<=20000;i++)
            dp[i] = 1e9;
        dp[a] = 0;
        for(int i=1;i<=c;i++){
            scanf("%d",&jump[i]);
        }
        sort(jump+1,jump+c+1);
        for(int i=a;i<=b;i++){
            if(dp[i] == 1e9)    continue;
            for(int j=1;j<=c;j++){
                if(i+jump[j]>b) break;
                dp[i+jump[j]] = min(dp[i+jump[j]],dp[i]+1);
            }
        }
        if(dp[b] == 1e9)    printf("-1\n");
        else                printf("%d\n",dp[b]);
    }
	return 0;
}
