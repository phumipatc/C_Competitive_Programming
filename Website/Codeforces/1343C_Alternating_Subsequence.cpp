/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[200010];
void solve(LL n){
	LL k = 1,last = (a[1]<0)?0:1,maxx = a[1],now,ans = 0;
	a[n+1] = (a[n]<0)?1:-1;
	for(LL i=1;i<=n+1;i++){
		now = (a[i]<0)?0:1;
		if(now!=last){
			ans+=maxx;
			maxx = a[i];
			last^=1;
			continue;
		}
		maxx = max(maxx,a[i]);
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	LL q,n;
	cin >> q;
	while(q--){
		cin >> n;
		for(LL i=1;i<=n;i++)
			cin >> a[i];
		solve(n);
	}
	return 0;
}