#include<bits/stdc++.h>
using namespace std;
struct A{
	int e,d;
	long long t;
};
struct B{
	int p,s;
	bool operator<(const B & o)const{
		if(s < o.s) return true;
		else		return false;
	}
};
struct C{
	int now,d,cost;
	long long t;
	bool operator<(const C & o)const{
		if(t > o.t) return true;
		else        return false;
	}
};
A temp;
B shoe[100010];
C tempp,now;
priority_queue<C>heap;
vector<A>v[100010];
int cost[100010];
int mark[100100];
int main(){
	int n,m,k,mt,a,b,l,minn = 1e7,ans = 1e7;
	scanf("%d %d %d %d",&n,&m,&k,&mt);
	for(int i=0; i<m; i++){
		scanf("%d %d %d %lld",&a,&b,&temp.d,&temp.t);
		temp.e = b;
		v[a].push_back(temp);
		temp.e = a;
		v[b].push_back(temp);
	}
	for(int i=1; i<=k; i++)
		scanf("%d %d",&shoe[i].p,&shoe[i].s);
	sort(shoe+1,shoe+k+1);
	b = k;
	for(l=100000; l>=0; l--){
		while(b > 0&&l == shoe[b].s)    minn = min(minn,shoe[b].p),b--;
		cost[l] = minn;
	}
	int p,q,ch = 0,round = 0;
	p = 1,q = 100000;
	while(p<q){
		round++;
		minn = (p+q)/2;
		tempp.now = 1,tempp.d = minn,tempp.t = 0;
		ch = 0;
		heap.push(tempp);
		while(!heap.empty()){
			now = heap.top();
			heap.pop();
			if(mark[now.now] == round)  continue;
			if(now.now == n){
				ch = 1;
				break;
			}
			mark[now.now] = round;
			for(int i=0; i<v[now.now].size(); i++){
				if(v[now.now][i].d > now.d) continue;
				tempp.now = v[now.now][i].e;
				tempp.d = now.d;
				tempp.t = now.t + v[now.now][i].t;
				if(mark[tempp.now] == round)    continue;
				heap.push(tempp);
			}
		}
		while(!heap.empty())    heap.pop();
		if(now.t > mt || !ch)   p = minn+1;
		else					ans = min(ans,cost[minn]),q = minn;
	}
	if(ans == 1e7)  printf("-1");
	else            printf("%d\n",ans);
	return 0;
}
