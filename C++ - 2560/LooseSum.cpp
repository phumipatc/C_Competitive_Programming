/*
	TASK: Loose Summation
	AUTHOR: PeaTT~
	SCHOOL: CRU
	LANG: CPP
*/
#include <bits/stdc++.h>
using namespace std;
int dp[5050]={1};
int main(){
    int n,k,i,j,q;
    scanf("%d",&q);
    for(i=1;i<=2000;i++)
        for(j=2000;j>=i;j--){
            dp[j]+=dp[j-i];
            dp[j]%=1000003;
        }
    while(q--){
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }
    return 0;
}
