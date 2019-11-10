#include<bits/stdc++.h>
using namespace std;
struct A
{
	int e,d;
	long long t;
};
struct SH
{
	int p,s;
	bool operator<(const SH & b)const
	{
		if(s < b.s)	 return true;
		else			return false;
	}
};
struct Dijk
{
	int now,d,cost;
	long long t;
	bool operator<(const Dijk & b)const
	{
		if(t > b.t)		return true;
		else			   return false;
	}
};
Dijk tp,now;
A tmp;
priority_queue<Dijk>q;
vector<A>v[100010];
SH sh[100010];
int cost[100010];
int mark[100100];
int main()
{
	int n,m,k,mt,a,b,l,mn = (int)1e7,ans = (int)1e7;
	scanf("%d %d %d %d",&n,&m,&k,&mt);
	for(int i=0; i<m; i++)
	{
		scanf("%d %d %d %lld",&a,&b,&tmp.d,&tmp.t);
		tmp.e = b;
		v[a].push_back(tmp);
		tmp.e = a;
		v[b].push_back(tmp);
	}
	for(int i=1; i<=k; i++)
		scanf("%d %d",&sh[i].p,&sh[i].s);
	sort(sh+1,sh+k+1);
	l = 100000;
	b = k;
	for(; l>=0; l--)
	{
		while(b > 0&&l == sh[b].s)
			mn = min(mn,sh[b].p),b--;
		cost[l] = mn;
	}
	int p,qq,mi,ch = 0,cc = 0;
	p = 1, qq = 100000;
	while(p<qq)
	{
		cc++;
		mi = (p+qq)/2;
		tp.now = 1,tp.d = mi,tp.t = 0;
		ch = 0;
		q.push(tp);
		while(!q.empty())
		{
			now = q.top();
			q.pop();
			if(mark[now.now] == cc)
				continue;
			if(now.now == n)
			{
				ch = 1;
				break;
			}
			mark[now.now] = cc;
			for(int i=0; i<v[now.now].size(); i++)
			{
				if(v[now.now][i].d > now.d)
					continue;
				tp.now = v[now.now][i].e;
				tp.d = now.d;
				tp.t = now.t + v[now.now][i].t;
				if(mark[tp.now] == cc)
					continue;
				q.push(tp);
			}
		}
		while(!q.empty())
			q.pop();
	   // memset(mark,0,sizeof mark);
		if(now.t > mt || !ch)	   p = mi+1;
		else						ans = min(ans,cost[mi]),qq = mi;
	}
	if(ans == (int)1e7)
		printf("-1");
	else
		printf("%d\n",ans);
	return 0;
}
