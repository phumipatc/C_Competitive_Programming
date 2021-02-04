/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
	int v,lv;
};
A tree[600100];
int a[150000],idx = 1;
void build(int l,int r,int now){
	if(l == r){
		tree[now].v = a[idx++];
		tree[now].lv = 1;
		// printf("now :%d %d %d %d\n",l,r,tree[now].v,tree[now].lv);
		return ;
	}
	int mid = (l+r)/2;
	build(l,mid,now*2);
	build(mid+1,r,now*2+1);
	tree[now].lv = tree[now*2].lv+1;
	if(tree[now].lv%2 == 0)
		tree[now].v = (tree[now*2].v|tree[now*2+1].v);
	else
		tree[now].v = (tree[now*2].v^tree[now*2+1].v);
	// printf("now :%d %d %d %d\n",l,r,tree[now].v,tree[now].lv);
}
void update(int l,int r,int now,int idx,int v){
	if(l == r && l == idx){
		tree[now].v = v;
		return ;
	}
	if(r<idx || l>idx)	return ;
	int mid = (l+r)/2;
	update(l,mid,now*2,idx,v);
	update(mid+1,r,now*2+1,idx,v);
	if(tree[now].lv%2 == 0)
		tree[now].v = (tree[now*2].v|tree[now*2+1].v);
	else
		tree[now].v = (tree[now*2].v^tree[now*2+1].v);
}
int main(){
	// freopen("0_in.txt","r",stdin);
	// freopen("0_out.txt","w",stdout);
	int n,m,v = 1;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)	v*=2;
	n = v;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,n,1);
	while(m--){
		scanf("%d %d",&idx,&v);
		update(1,n,1,idx,v);
		printf("%d\n",tree[1].v);
	}
	return 0;
}
