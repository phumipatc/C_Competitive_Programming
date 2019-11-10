/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[10],dp[1000200];
int main(){
	int q,n,m;
	cin >> q;
	for(int x = 1;x<=q;x++){
		cin >> n >> m;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		dp[0] = x;
		for(int i=0;i<=m;i++){
			if(dp[i] == x){
				for(int j=1;j<=n;j++){
					dp[i+a[j]] = x;
				}
			}
		}
		int countt = 0;
		for(int i=1;i<=m;i++){
			if(dp[i] == x)
				countt++;
		}
		cout << countt << endl;
	}
	return 0;
}
