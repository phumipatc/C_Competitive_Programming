/*
	Task	: jumps
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 22 May 2021 [13:29]
	Algo	: 
	Status	: 
*/
#include<bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= (b); ++i)
#define ROF(i, a, b) for(int i = a; i >= (b); --i)
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
#include "jumps.h"
const int mxN = 200010;
int n,a[mxN],l[mxN],r[mxN],in[mxN],in2[mxN],dp[mxN];
vector<int > g[mxN];
vector<PII > t[mxN];
int cnt;
void dfs(int u){
	t[u].push_back({0,0});
	t[u].back().first = ++cnt;
	for(auto x:g[u]){
		dfs(x);
	}
	t[u].back().second = ++cnt;
}
void init(int N, std::vector<int> H) {
	n = N;
	FOR(i,0,sz(H)-1)
		a[i+1] = H[i];
	stack<PII > s;
    s.push({a[1],1});
	FOR(i,2,n){
        if(s.empty()){
            s.push({a[i],i});
            continue;
        }
        while(s.empty() == false && s.top().first < a[i]){
			r[s.top().second] = i;
            s.pop();
        }
        s.push({a[i],i});
    }
	while(!s.empty())	s.pop();
	s.push({a[n],n});
	ROF(i,n-1,1)
    {
        if(s.empty()){
            s.push({a[i],i});
            continue;
        }
        while(s.empty() == false && s.top().first < a[i]){
			l[s.top().second] = i;
            s.pop();
        }
        s.push({a[i],i});
    }
	// FOR(i,1,n){
	// 	printf("%d %d\n",l[i],r[i]);
	// }
	FOR(i,1,n){
		if(l[i])	g[l[i]].push_back(i),in[i]++,in2[l[i]]++;
		if(r[i])	g[r[i]].push_back(i),in[i]++,in2[r[i]]++;
	}
	FOR(i,1,n){
		if(in[i])	continue;
		dfs(i);
	}
	queue<int > que;
	FOR(i,1,n){
		if(in2[i])	continue;
		que.push(i);
		dp[i] = 1;
	}
	while(!que.empty()){
		int now = que.front();
		que.pop();
		if(l[now]){
			if(dp[l[now]] == 0)	dp[l[now]] = 1e9;
			dp[l[now]] = min(dp[l[now]],dp[now]+1);
			in2[l[now]]--;
			if(!in2[l[now]])	que.push(l[now]);
		}
		if(r[now]){
			if(dp[r[now]] == 0)	dp[r[now]] = 1e9;
			dp[r[now]] = min(dp[r[now]],dp[now]+1);
			in2[r[now]]--;
			if(!in2[r[now]])	que.push(r[now]);
		}
	}
}
int minimum_jumps(int A, int B, int C, int D) {
	A++,B++,C++,D++;
	int idx = lower_bound(all(t[A]),make_pair(t[C][0].first,0))-t[A].begin();
	if(t[A][idx].second<=t[C][0].second)	return dp[C]-dp[A];
	else									return -1;
}
