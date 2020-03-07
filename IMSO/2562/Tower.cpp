/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define l_node now*2
#define r_node now*2+1
using namespace std;
typedef long long LL;
struct A{
	int v,l,r,countt;
};
A tree[800010];
int lazy[800010];
void upd(int l,int r,int now,int ll,int rr,int v){
	if(lazy[now]){
		tree[now].v+=lazy[now];
		tree[now].l+=lazy[now];
		tree[now].r+=lazy[now];
		if(l!=r)	lazy[l_node]+=lazy[now],lazy[r_node]+=lazy[now];
		lazy[now] = 0;
	}
	if(r<ll || l>rr)	return ;
	if(ll<=l && r<=rr){
		tree[now].v+=v;
		tree[now].l+=v;
		tree[now].r+=v;
		if(l!=r){
			lazy[l_node]+=v;
			lazy[r_node]+=v;
		}
		return ;
	}
	int mid = (l+r)/2;
	upd(l,mid,l_node,ll,rr,v);
	upd(mid+1,r,r_node,ll,rr,v);
	if(tree[l_node].v>tree[r_node].v){
		tree[now] = tree[l_node];
	}else if(tree[r_node].v>tree[l_node].v){
		tree[now] = tree[r_node];
	}else{
		tree[now] = tree[l_node];
		tree[now].countt+=tree[r_node].countt;
		if(tree[l_node].r == tree[r_node].v && tree[r_node].l == tree[l_node].v)
			tree[now].countt--;
	}
	tree[now].l = tree[l_node].l;
	tree[now].r = tree[r_node].r;
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,m,u,v,w;
	cin >> n >> m;
	for(int i=1;i<=4*n;i++)
		tree[i].countt = 1;
	while(m--){
		cin >> u >> v >> w;
		upd(1,n,1,u,v,w);
		cout << tree[1].v << ' ' << tree[1].countt << '\n';
	}
	return 0;
}