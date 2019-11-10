/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
	long long in,out;
};
A a[100100];
struct B{
	long long sum,minn;
};
B tree[800100],minn;
vector<long long > g[100100];
long long t[200100],v[100100],lazy[800100],idx = 1;
void dfs(long long now){
	a[now].in = idx;
	t[idx++] = now;
	for(long long i=0;i<g[now].size();i++){
		dfs(g[now][i]);
	}
	a[now].out = idx;
	t[idx++] = now;
}
void update(long long l,long long r,long long now,long long ll,long long rr,long long v){
	if(lazy[now]){
		tree[now].sum+=(r-l+1)*lazy[now];
		tree[now].minn+=lazy[now];
		if(l!=r){
			lazy[now*2]+=lazy[now];
			lazy[now*2+1]+=lazy[now];
		}
		lazy[now] = 0;
	}
	if(r<ll || rr<l)	return ;
	if(ll<=l && r<=rr){
		tree[now].sum+=(r-l+1)*v;
		tree[now].minn+=v;
		if(l!=r){
			lazy[now*2]+=v;
			lazy[now*2+1]+=v;
		}
		return ;
	}
	long long mid = (l+r)/2;
	update(l,mid,now*2,ll,rr,v);
	update(mid+1,r,now*2+1,ll,rr,v);
	tree[now].sum = tree[now*2].sum+tree[now*2+1].sum;
	tree[now].minn = min(tree[now*2].minn,tree[now*2+1].minn);
}
B query(long long l,long long r,long long now,long long ll,long long rr){
	if(lazy[now]){
		tree[now].sum+=(r-l+1)*lazy[now];
		tree[now].minn+=lazy[now];
		if(l!=r){
			lazy[now*2]+=lazy[now];
			lazy[now*2+1]+=lazy[now];
		}
		lazy[now] = 0;
	}
	if(r<ll || rr<l)	return {(long long)-1e9,(long long)-1e9};
	if(ll<=l && r<=rr)	return tree[now];
	long long mid = (l+r)/2;
	B q1 = query(l,mid,now*2,ll,rr);
	B q2 = query(mid+1,r,now*2+1,ll,rr);
	if(q1.minn == -1e9)	return q2;
	if(q2.minn == -1e9)	return q1;
	return {q1.sum+q2.sum,min(q1.minn,q2.minn)};
}
int main(){
	// freopen("0_in.txt","r",stdin);
	// freopen("0_out.txt","w",stdout);
	long long q,n,m,u,w,opr,id;
	scanf("%lld",&q);
	for(long long Q=1;Q<=q;Q++){
		scanf("%lld %lld",&n,&m);
		for(long long i=1;i<=n;i++){
			scanf("%lld %lld",&u,&w);
			v[i] = w;
			g[u].push_back(i);
		}
		dfs(1);
		for(long long i=1;i<=n;i++){
			update(1,2*n,1,a[i].in,a[i].in,v[i]);
			update(1,2*n,1,a[i].out,a[i].out,v[i]);
		}
		printf("Case %lld:\n",Q);
		while(m--){
			scanf("%lld %lld",&opr,&id);
			if(opr == 1){
				printf("%lld\n",query(1,2*n,1,a[id].in,a[id].out).sum/2);
			}else{
				minn = query(1,2*n,1,a[id].in,a[id].out);
				update(1,2*n,1,a[id].in,a[id].out,min(minn.minn,1000ll));
			}
		}
		for(int i=0;i<=n;i++)
			g[i].clear();
		memset(a,0,sizeof a);
		memset(tree,0,sizeof tree);
		memset(t,0,sizeof t);
		memset(v,0,sizeof v);
		memset(lazy,0,sizeof lazy);
		idx = 1;
	}
	return 0;
}
