/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int bomb[25],dp[1030];
int main(){
    int n,m,temp,num;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        while(temp--){
            scanf("%d",&num);
            bomb[i]|=1<<(num-1);
        }
    }
    for(int i=1;i<(1<<m);i++){
        dp[i] = 1e9;
        for(int j=0;j<n;j++){
            num = i;
            for(int k=0;k<m;k++){
                if(((1<<k) & num) == 0)     continue;
                if(((1<<k) & bomb[j]) == 0) continue;
                num^=(1<<k);
            }
            dp[i] = min(dp[i],dp[num]+1);
        }
    }
    printf("%d\n",dp[(1<<m)-1]);
	return 0;
}
