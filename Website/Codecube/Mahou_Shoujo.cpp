/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010],dp[100010];
int main(){
    int n,k;
    while(1){
        cin >> n >> k;
        printf("%d %d %d %d %d %d\n",n&k,n|k,n^k,-n-1,n<<3,n>>2);
    }
	return 0;
}