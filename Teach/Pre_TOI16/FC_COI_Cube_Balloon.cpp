/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: DSU
	Status	: Finished
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int ,int > PII;
typedef pair<long long ,long long > PLL;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
struct A{
	int t,idx,w;
	bool operator < (const A&o) const{
		return t>o.t;
	}
};
priority_queue<A > heap;
int sum[100010];
int p[100010];
int fr(int u){
	if(p[u] == u)	return u;
	else			return fr(p[u]);
}
void upd(int now,int target){
	sum[now]-=sum[target];
	if(p[now] == now)	return ;
	else				upd(p[now],target);
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,m,u,v,w,t,rv,opr;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> w;
		sum[i] = w,p[i] = i;
	}
	for(int i=1;i<=m;i++){
		cin >> opr;
		while(!heap.empty() && i == heap.top().t){
			auto now = heap.top();
			heap.pop();
			rv = fr(now.idx);
			sum[rv]+=now.w;
		}
		if(opr == 1){
			cin >> u;
			if(p[u] == u)	continue;
			upd(p[u],u);
			p[u] = u;
		}else if(opr == 2){
			cin >> u >> v >> t >> w;
			rv = fr(v);
			if(rv == u)		continue;
			if(p[u] != u)	upd(p[u],u);
			p[u] = rv;
			sum[rv]+=sum[u];
			heap.push({t,u,w});
		}else if(opr == 3){
			cin >> v;
			rv = fr(v);
			cout << sum[rv] << '\n';
		}
	}
	return 0;
}
