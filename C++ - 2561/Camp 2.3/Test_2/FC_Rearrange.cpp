/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[10010],a[10010];
int main(){
    int q,n,k,maxx;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&k);
        memset(dp,0,sizeof dp);
        dp[0] = 1,maxx = 0;
        for(int i=1;i<=k;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+k+1);
        for(int i=1;i<k;i++){
            for(int j=n-1;j>=0;j--){
                if(!dp[j])      continue;
                if(j+a[i]>=n)   continue;
                dp[j+a[i]] = 1;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(!dp[i])  continue;
            maxx = i;
            break;
        }
        if(n == 0)  maxx = 0;
        printf("%d\n",n-maxx-a[k]);
    }
	return 0;
}
