/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[200010],p[200010];
int mark[200010];
int fr(int i){
	if(p[i] == i)	return i;
	else			return p[i] = fr(p[i]);
}
void dfs(int u,int pa,int state){
	mark[u] = state;
	if(pa)			p[u] = pa;
	if(!mark[a[u]])	dfs(a[u],u,state+1);
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,q;
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		p[i] = i;
	}
	for(int i=1;i<=n;i++){
		if(mark[i])	continue;
		dfs(i,0,1);
	}
	int s,e,u,v;
	while(q--){
		cin >> s >> e >> u >> v;
		int rs = fr(s),re = fr(e),ru = fr(u),rv = fr(v);
		if(rs!=re){
			if((ru == re && rv == rs) || (ru == rs && rv == re))
				cout << "DEAD\n";
			else
				cout << "SURVIVE\n";
		}else{
			if(ru!=re || rv!=re || u == v){
				cout << "DEAD\n";
				continue;
			}
			if(mark[u]>mark[v])	swap(u,v);
			int x = mark[e]>=mark[u]+1 && mark[e]<=mark[v];
			int y = mark[s]>=mark[u]+1 && mark[s]<=mark[v];
			if(x == y)	cout << "DEAD\n";
			else		cout << "SURVIVE\n";
		}
	}
	return 0;
}