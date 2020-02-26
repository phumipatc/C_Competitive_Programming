/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[1000010];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,k,maxx = 0;
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		a[i]+=a[i-1];
		if(i<k)	continue;
		maxx = max(maxx,a[i]-a[i-k]);
	}
	cout << maxx << '\n';
	return 0;
}