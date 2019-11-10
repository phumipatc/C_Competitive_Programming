/*
	TASK: Stair
	AUTHOR: PeaTT~
	SCHOOL: CRU
	LANG: CPP
*/
#include <bits/stdc++.h>
using namespace std;
int dp[5050]={1};
int main(){
    int n,k,i,j;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
        for(j=n;j>=i;j--){
            dp[j]+=dp[j-i];
            dp[j]%=k;
        }
    printf("%d\n",dp[n]-1);
    return 0;
}
