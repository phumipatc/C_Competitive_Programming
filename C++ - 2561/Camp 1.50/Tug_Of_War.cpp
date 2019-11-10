/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000100],dp[1000100];
int main(){
    int n,num,last = 0;
    cin >> n >> last;
    for(int i=1;i<n;i++){
        cin >> num;
        a[i] = num-last;
        last = num;
    }
    dp[1] = a[1];
    for(int i=2;i<n;i++)
        dp[i] = max(dp[i-1],dp[i-2]+a[i]);
    printf("%d\n",dp[n-1]);
	return 0;
}
