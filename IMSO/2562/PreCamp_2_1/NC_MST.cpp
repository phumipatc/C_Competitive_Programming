/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
struct A{
	long long u,v,w;
	bool operator < (const A&o) const{
		if(w!=o.w)		return w<o.w;
		else if(u!=o.u)	return u<o.u;
		else			return v<o.v;
	}
	bool operator == (const A&o) const{
		if(u!=o.u)		return false;
		else if(v!=o.v)	return false;
		else			return true;
	}
};
A a[100010];
vector<A > now;
long long p[40010],mark[40010];
long long fr(long long i){
	if(p[i] == i)	return p[i];
	else			return p[i] = fr(p[i]);
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	long long n,m,u,v,w,ru,rv;
	cin >> n >> m;
	for(long long i=1;i<=m;i++){
		cin >> u >> v >> w;
		if(u>v)	swap(u,v);
		a[i] = {u,v,w};
	}
	for(long long i=1;i<=n;i++)
		p[i] = i;
	sort(a+1,a+m+1);
	long long sum = 0,ans = 1,group;
	for(long long i=1;i<=m;i++){
		ru = fr(a[i].u);
		rv = fr(a[i].v);
		if(ru>rv)	swap(ru,rv);
		if(ru!=rv)
			now.push_back({ru,rv,a[i].w});
		if(a[i].w == a[i+1].w)	continue;
		group = 0;
		for(auto x:now){
			if(!mark[x.u]){
				mark[x.u] = 1;
				group++;
			}
			if(!mark[x.v]){
				mark[x.v] = 1;
				group++;
			}
		}
		if(now.size() == 2){
			//2 edges
			if(group == 2){
				ans*=2;
				ans%=MOD;
				sum+=a[i].w;
				sum%=MOD;
			}else{
				sum+=a[i].w*2;
				sum%=MOD;
			}
			for(auto x:now)
				mark[x.u] = mark[x.v] = 0;
			for(auto x:now){
				ru = fr(x.u);
				rv = fr(x.v);
				p[ru] = rv;
			}
			now.clear();
		}else if(now.size() == 3){
			//3 edges
			if(group == 2){
				ans*=3;
				ans%=MOD;
				sum+=a[i].w;
				sum%=MOD;
			}else if(group == 3){
				if(now[0] == now[1] || now[1] == now[2] || now[0] == now[2]){
					ans*=2;
					ans%=MOD;
					sum+=a[i].w*2;
					sum%=MOD;
				}else{
					ans*=3;
					ans%=MOD;
					sum+=a[i].w*2;
					sum%=MOD;
				}
			}else{
				sum+=a[i].w*3;
				sum%=MOD;
			}
			for(auto x:now)
				mark[x.u] = mark[x.v] = 0;
			for(auto x:now){
				ru = fr(x.u);
				rv = fr(x.v);
				p[ru] = rv;
			}
			now.clear();
		}else if(now.size() == 1){
			//1 edge
			sum+=a[i].w;
			sum%=MOD;
			for(auto x:now)
				mark[x.u] = mark[x.v] = 0;
			for(auto x:now){
				ru = fr(x.u);
				rv = fr(x.v);
				p[ru] = rv;
			}
			now.clear();
		}
	}
	cout << sum << ' ' << ans << '\n';
	return 0;
}