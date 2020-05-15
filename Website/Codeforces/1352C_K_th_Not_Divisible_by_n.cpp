/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
void solve(int n,int k){
	LL l = 1,r = 2e9;
	while(l<r){
		LL mid = (l+r)/2;
		// printf("%lld %lld %lld\n",l,r,mid);
		if(mid-(mid/n)>=k)		r = mid;
		else if(mid-(mid/n)<k)	l = mid+1;
	}
	cout << l << '\n';
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q,n,k;
	cin >> q;
	while(q--){
		cin >> n >> k;
		solve(n,k);
	}
	return 0;
}