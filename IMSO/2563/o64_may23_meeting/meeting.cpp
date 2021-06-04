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
int LCA[100010][20],lv[100010],dis[100010][20];
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
PII fLCA(int u,int v,int sum=0){
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
PII fnode(int u,int lv,int sum=0){
	for(int i=18;i>=0;i--){
		if(!(lv & (1<<i)))	continue;
		sum+=dis[u][i];
		u = LCA[u][i];
	}
	return {u,sum};
}
vector<int> best_meeting(int N, int Q,
			 vector<vector<int>>& roads,
			 vector<int>& lengths,
			 vector<int>& A,
			 vector<int>& B,
			 vector<int>& C)
{
	rep(i,0,N-2){
		g[roads[i][0]].push_back({roads[i][1],lengths[i]});
		g[roads[i][1]].push_back({roads[i][0],lengths[i]});
	}
	dfs(0,-1,1,0);
	vector<int > ans;
	rep(q,0,Q-1){
		int a = A[q],b = B[q],c = C[q];
		PII ab = fLCA(a,b);
		PII bc = fLCA(b,c);
		PII ac = fLCA(a,c);
		PII abc = fLCA(ab.first,c);
		if(ab.first!=abc.first);
		else if(ac.first!=abc.first)	swap(b,c);
		else if(bc.first!=abc.first)	swap(a,c);

		ab = fLCA(a,b);
		int minn = 2e9;
		if(max(fLCA(a,abc.first).second,fLCA(b,abc.first).second)<=fLCA(c,abc.first).second){
			int l = 0,r = lv[c]-lv[abc.first],mid,w = max(fLCA(a,abc.first).second,fLCA(b,abc.first).second);
			PII ret;
			while(l<r){
				mid = (l+r+1)/2;
				ret = fnode(c,mid);
				if(w+fLCA(abc.first,ret.first).second>=ret.second)	l = mid;
				else												r = mid-1;
			}
			PII now = fnode(c,l);
			minn = min(minn,max({fLCA(a,now.first).second,fLCA(b,now.first).second,fLCA(c,now.first).second}));
			if(now.first)
				minn = min(minn,max({fLCA(a,LCA[now.first][0]).second,fLCA(b,LCA[now.first][0]).second,fLCA(c,LCA[now.first][0]).second}));
		}else if(max(fLCA(a,ab.first).second,fLCA(b,ab.first).second)<=fLCA(c,ab.first).second){
			int l = 0,r = lv[ab.first]-lv[abc.first],mid,w = max(fLCA(a,ab.first).second,fLCA(b,ab.first).second);
			PII ret;
			while(l<r){
				mid = (l+r+1)/2;
				ret = fnode(ab.first,mid);
				if(w+fLCA(ab.first,ret.first).second<=fLCA(c,ret.first).second)	l = mid;
				else															r = mid-1;
			}
			PII now = fnode(ab.first,l);
			minn = min(minn,max({fLCA(a,now.first).second,fLCA(b,now.first).second,fLCA(c,now.first).second}));
			if(now.first)
				minn = min(minn,max({fLCA(a,LCA[now.first][0]).second,fLCA(b,LCA[now.first][0]).second,fLCA(c,LCA[now.first][0]).second}));
		}else if(fLCA(a,ab.first).second<=fLCA(b,ab.first).second){
			int l = 0,r = lv[b]-lv[ab.first],mid,w = max(fLCA(a,ab.first).second,fLCA(c,ab.first).second);
			PII ret;
			while(l<r){
				mid = (l+r+1)/2;
				ret = fnode(b,mid);
				if(w+fLCA(ab.first,ret.first).second>=ret.second)	l = mid;
				else												r = mid-1;
			}
			PII now = fnode(b,l);
			minn = min(minn,max({fLCA(a,now.first).second,fLCA(b,now.first).second,fLCA(c,now.first).second}));
			if(now.first)
				minn = min(minn,max({fLCA(a,LCA[now.first][0]).second,fLCA(b,LCA[now.first][0]).second,fLCA(c,LCA[now.first][0]).second}));
		}else{
			int l = 0,r = lv[a]-lv[ab.first],mid,w = max(fLCA(b,ab.first).second,fLCA(c,ab.first).second);
			PII ret;
			while(l<r){
				mid = (l+r+1)/2;
				ret = fnode(a,mid);
				if(w+fLCA(ab.first,ret.first).second>=ret.second)	l = mid;
				else												r = mid-1;
			}
			PII now = fnode(a,l);
			minn = min(minn,max({fLCA(a,now.first).second,fLCA(b,now.first).second,fLCA(c,now.first).second}));
			if(now.first)
				minn = min(minn,max({fLCA(a,LCA[now.first][0]).second,fLCA(b,LCA[now.first][0]).second,fLCA(c,LCA[now.first][0]).second}));
		}
		ans.push_back(minn);
	}
	return ans;
}