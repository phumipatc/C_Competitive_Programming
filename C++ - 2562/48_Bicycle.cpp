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
map<int ,int > mapp;
int p[50010];
int find_root(int i){
	if(p[i] == i)	return i;
	else			return p[i] = find_root(p[i]);
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q,n,m,num,u,v,w,ru,rv;
	cin >> q;
	while(q--){
		cin >> n >> m;
		for(int i=1;i<=n;i++){
			cin >> num;
			mapp[num] = i;
			p[i] = i;
		}
		while(m--){
			cin >> u >> v >> w;
			heap.push({mapp[u],mapp[v],w});
		}
		int ans = 0;
		while(!heap.empty()){
			now = heap.top();
			heap.pop();
			ru = find_root(now.u);
			rv = find_root(now.v);
			if(ru == rv)
				ans+=now.w;
			p[ru] = rv;
		}
		cout << ans << '\n';
	}
	return 0;
}