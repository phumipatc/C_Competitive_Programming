/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q,n,m,l,r,ll,rr;
	cin >> q;
	while(q--){
		cin >> n >> l >> m;
		r = l;
		while(m--){
			cin >> ll >> rr;
			if(r<ll || l>rr)	continue;
			l = min(l,ll);
			r = max(r,rr);
		}
		cout << r-l+1 << '\n';
	}
	return 0;
}