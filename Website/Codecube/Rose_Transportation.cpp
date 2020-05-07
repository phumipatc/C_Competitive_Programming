/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct A{
	int u,v,w;
	bool operator < (const A&o) const{
		return w<o.w;
	}
};
A now;
priority_queue<A > heap;
int a[100010],p[100010];
int fr(int i){
	if(p[i] == i)	return i;
	else			return p[i] = fr(p[i]);
}
void solve(){
	int ans = 0;
	while(!heap.empty()){
		now = heap.top();
		heap.pop();
		int ru = fr(now.u);
		int rv = fr(now.v);
		if(ru == rv)	continue;
		ans+=now.w;
		p[ru] = rv;
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,m,u,v;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		p[i] = i;
	}
	while(m--){
		cin >> u >> v;
		heap.push({u,v,a[u]+a[v]});
	}
	solve();
	return 0;
}