/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
	int v,l,r,ans;
};
A tree[800100],temp;
int v[200100],idx = 1;
void build(int l,int r,int now){
	if(l == r){
		tree[now].v = v[idx++];
		tree[now].l = tree[now].r = min(0,tree[now].v);
		tree[now].ans = tree[now].v;
		return ;
	}
	int mid = (l+r)/2;
	build(l,mid,now*2);
	build(mid+1,r,now*2+1);
	tree[now].v = tree[now*2].v+tree[now*2+1].v;
	tree[now].l = min(tree[now*2].l,tree[now*2].v+tree[now*2+1].l);
	tree[now].r = min(tree[now*2+1].r,tree[now*2].r+tree[now*2+1].v);
	tree[now].ans = max(tree[now*2].ans,max(tree[now*2+1].ans,tree[now].v-tree[now*2].l-tree[now*2+1].r));
}
A query(int l,int r,int now,int ll,int rr){
	if(r<ll || rr<l)	return {(int)1e9,(int)1e9,(int)1e9,(int)1e9};
	if(ll<=l && r<=rr)	return tree[now];
	int mid = (l+r)/2;
	A l_node = query(l,mid,now*2,ll,rr);
	A r_node = query(mid+1,r,now*2+1,ll,rr);
	A now_node;
	if(l_node.ans == 1e9)	return r_node;
	if(r_node.ans == 1e9)	return l_node;
	now_node.v = l_node.v+r_node.v;
	now_node.l = min(l_node.l,l_node.v+r_node.l);
	now_node.r = min(r_node.r,r_node.v+l_node.r);
	now_node.ans = max(l_node.ans,max(r_node.ans,now_node.v-l_node.l-r_node.r));
	return now_node;
}
int main(){
	freopen("0_in.txt","r",stdin);
	freopen("0_out.txt","w",stdout);
	int n,m,l,r;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	build(1,n,1);
	while(m--){
		scanf("%d %d",&l,&r);
		l++,r++;
		temp = query(1,n,1,l,r);
		printf("%d\n",max(0,temp.ans));
	}
	return 0;
}
