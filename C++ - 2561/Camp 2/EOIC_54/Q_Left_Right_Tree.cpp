/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 9999991
using namespace std;
int dp[130][130];
int query(int l,int r){
    if(r == 0 && l == 0)    return 0;
    if(r == 0 || l == 0)    return 1;
    if(dp[l][r])            return dp[l][r];
    
}
int main(){
    int q,n,m;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n,&m);
        printf("%d\n",query(n,m));
    }
	return 0;
}
