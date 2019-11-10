#include<bits/stdc++.h>
#define l_node now*2
#define r_node now*2+1
using namespace std;
struct A{
	int v,l,r,countt;
};
A tree[800100];
pair<int,int> lazy[800100];
void update(int l,int r,int now,int ll,int rr,int v){
	if(lazy[now].first){
		tree[now].v+=lazy[now].second;
		tree[now].l+=lazy[now].second;
		tree[now].r+=lazy[now].second;
		if(l!=r){
			lazy[l_node].first = 1;
			lazy[r_node].first = 1;
			lazy[l_node].second+=lazy[now].second;
			lazy[r_node].second+=lazy[now].second;
		}
		lazy[now].first = 0;
		lazy[now].second = 0;
	}
	if(r<ll || rr<l)	return ;
	if(ll<=l && r<=rr){
		tree[now].v+=v;
		tree[now].l+=v;
		tree[now].r+=v;
		if(l!=r){
			lazy[l_node].first = 1;
			lazy[l_node].second+=v;
			lazy[r_node].first = 1;
			lazy[r_node].second+=v;
		}
		return ;
	}
	int mid = (l+r)/2;
	update(l,mid,l_node,ll,rr,v);
	update(mid+1,r,r_node,ll,rr,v);
	if(tree[l_node].v>tree[r_node].v)
		tree[now] = tree[l_node];
	else if(tree[l_node].v<tree[r_node].v)
		tree[now] = tree[r_node];
	else{
		tree[now] = tree[l_node];
		tree[now].countt+=tree[r_node].countt;
		if(tree[l_node].r == tree[r_node].v && tree[l_node].v == tree[r_node].l)
			tree[now].countt--;
	}
	tree[now].l = tree[l_node].l;
	tree[now].r = tree[r_node].r;
}
int main(){
	freopen("0_in.txt","r",stdin);
	freopen("0_out.txt","w",stdout);
	int n,m,l,r,v;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=4*n;i++)	tree[i].countt = 1;
	while(m--){
		scanf("%d %d %d",&l,&r,&v);
		update(1,n,1,l,r,v);
		printf("%d %d\n",tree[1].v,tree[1].countt);
	}
	return 0;
}