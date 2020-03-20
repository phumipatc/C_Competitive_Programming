/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct A{
	int u,v;
	double w;
	bool operator < (const A&o) const{
		return w<o.w;
	}
};
A now;
vector<A > g;
int pos[490010],speed[490010];
int p[490010],countt[490010];
int n,maxx = 1;
int num(int i,int j){
	return ((i-1)*n)+j;
}
int find_root(int i){
	if(p[i] == i)	return i;
	else			return find_root(p[i]);
}
void join(int u,int v){
	if(speed[u] == speed[v]){
		if(pos[u] == pos[v]){
			int ru = find_root(u);
			int rv = find_root(v);
			if(ru!=rv){
				maxx = max(maxx,countt[ru]+countt[rv]);
				if(countt[ru]>=countt[rv]){
					p[rv] = ru;
					countt[ru]+=countt[rv];
				}else{
					p[ru] = rv;
					countt[rv]+=countt[ru];
				}
			}
		}
		return ;
	}
	now = {u,v,(double )(pos[v]-pos[u])/(speed[u]-speed[v])};
	if(now.w>=0)	g.push_back(now);
}
vector<A > order;
void backtrack(){
	reverse(order.begin(),order.end());
	for(auto x:order){
		countt[x.u]-=countt[x.v];
		p[x.v] = x.v;
	}
	order.clear();
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int ru,rv;
	cin >> n;
	for(int i=1;i<=n*n;i++)
		p[i] = i,countt[i] = 1;
	for(int i=1;i<=n*n;i++)
		cin >> pos[i];
	for(int i=1;i<=n*n;i++)
		cin >> speed[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j+1<=n)	join(num(i,j),num(i,j+1));
			if(i+1<=n)	join(num(i,j),num(i+1,j));
		}
	}
	sort(g.begin(),g.end());
	for(int i=0;i<g.size();i++){
		if(i != 0 && g[i].w!=g[i-1].w)	backtrack();
		ru = find_root(g[i].u);
		rv = find_root(g[i].v);
		if(ru == rv)	continue;
		maxx = max(maxx,countt[ru]+countt[rv]);
		if(countt[ru]>=countt[rv]){
			countt[ru]+=countt[rv];
			p[rv] = ru;
			order.push_back({ru,rv,0});
		}else{
			countt[rv]+=countt[ru];
			p[ru] = rv;
			order.push_back({rv,ru,0});
		}
	}
	cout << maxx << '\n';
	return 0;
}