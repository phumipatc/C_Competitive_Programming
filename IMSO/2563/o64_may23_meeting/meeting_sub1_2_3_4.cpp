/*
	Task	: meeting
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 23 May 2021 [13:14]
	Algo	: 
	Status	: 
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i <= (b); ++i)
#define repr(i, a, b) for(int i = a; i >= (b); --i)
#define all(x) begin(x),end(x)
#define allst(x,y) (x).begin()+y,(x).end()
#define rmdup(x) (x).resize(unique((x).begin(),(x).end())-(x).begin())
#define sz(x) (int)(x).size()
#define decp(x) fixed << setprecision(x)
#define MOD (LL )(1e9+7)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2,c);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
#include "meeting.h"
vector<PII > g[100010];
int LCA[100010][20],dis[100010][20],lv[100010];
void dfs(int u,int p,int lvl,int w){
	LCA[u][0] = p;
	dis[u][0] = w;
	lv[u] = lvl;
	rep(i,1,18){
		LCA[u][i] = LCA[LCA[u][i-1]][i-1];
		dis[u][i] = dis[u][i-1] + dis[LCA[u][i-1]][i-1];
	}
	for(auto x:g[u]){
		if(x.first == p)	continue;
		dfs(x.first,u,lvl+1,x.second);
	}
}
PII find_LCA(int u,int v,int sum=0){
	if(lv[u]<lv[v])	swap(u,v);
	for(int i=18;i>=0;i--){
		if(lv[LCA[u][i]]<lv[v])	continue;
		sum+=dis[u][i];
		u = LCA[u][i];
	}
	if(u == v)	return {u,sum};
	for(int i=18;i>=0;i--){
		if(LCA[u][i] == LCA[v][i])	continue;
		sum+=dis[u][i] + dis[v][i];
		u = LCA[u][i],v = LCA[v][i];
	}
	sum+=dis[u][0] + dis[v][0];
	return {LCA[u][0],sum};
}
PII find_node(int u,int lv,int sum=0){
	for(int i=18;i>=0;i--){
		if(!(lv & (1<<i)))	continue;
		sum+=dis[u][i];
		u = LCA[u][i];
	}
	return {u,sum};
}
int dist2[1010][1010];
vector<int> best_meeting(int N, int Q,
			 vector<vector<int>>& roads,
			 vector<int>& lengths,
			 vector<int>& a,
			 vector<int>& b,
			 vector<int>& c)
{
	rep(i,0,N-2){
		g[roads[i][0]].push_back({roads[i][1],lengths[i]});
		g[roads[i][1]].push_back({roads[i][0],lengths[i]});
	}
	if(N<=1000 && Q<=50000){
		dfs(0,-1,1,0);
		rep(i,0,N-1)
			rep(j,0,N-1)
				dist2[i][j] = find_LCA(i,j).second;
		vector<int > ans;
		rep(q,0,Q-1){
			int minn = 1e9;
			rep(i,0,N-1)
				minn = min(minn,max({dist2[i][a[q]],dist2[i][b[q]],dist2[i][c[q]]}));
			ans.push_back(minn);
		}
		return ans;
	}
	dfs(0,-1,1,0);
	vector<int > ans;
	rep(q,0,Q-1){
		int mn = min({a[q],b[q],c[q]}),mx = max({a[q],b[q],c[q]});
		PII p = find_LCA(mn,mx);
		int ll = find_LCA(mn,p.first).second;
		if(ll == p.second/2){
			ans.push_back(max(ll,p.second-ll));
			continue;
		}
		if(ll<p.second/2){
			// Go right
			int l = 0,r = lv[mx]-lv[p.first];
			while(l<r){
				int mid = (l+r+1)/2;
				int ret = find_node(mx,mid).second;
				if(ret>p.second/2)	r = mid-1;
				else				l = mid;
			}
			int tl = find_node(mx,l).second,tr = find_node(mx,l+1).second;
			ans.push_back(min(max(tl,p.second-tl),max(tr,p.second-tr)));
		}else{
			// Go left
			int l = 0,r = lv[mn]-lv[p.first];
			while(l<r){
				int mid = (l+r+1)/2;
				int ret = find_node(mn,mid).second;
				if(ret>p.second/2)	r = mid-1;
				else				l = mid;
			}
			int tl = find_node(mn,l).second,tr = find_node(mn,l+1).second;
			ans.push_back(min(max(tl,p.second-tl),max(tr,p.second-tr)));
		}
	}
	return ans;
}