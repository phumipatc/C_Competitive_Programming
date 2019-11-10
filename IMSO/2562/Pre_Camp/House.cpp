/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,l,r,ans;
};
A tree[800010];
int a[200010];
void build(int l,int r,int now){
    if(l == r){
        tree[now].ans = tree[now].v = a[l];
        tree[now].l = tree[now].r = min(0,a[l]);
        return ;
    }
    int mid = (l+r)/2;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    tree[now].v = tree[now*2].v+tree[now*2+1].v;
    tree[now].l = min(tree[now*2].l,tree[now*2].v+tree[now*2+1].l);
    tree[now].r = min(tree[now*2+1].r,tree[now*2+1].v+tree[now*2].r);
    tree[now].ans = max(tree[now*2].ans,max(tree[now*2+1].ans,tree[now].v-tree[now*2].l-tree[now*2+1].r));
}
A query(int l,int r,int now,int ll,int rr){
    if(rr<l || ll>r)    return {(int )1e9,(int )1e9,(int )1e9,(int )1e9};
    if(ll<=l && r<=rr)  return tree[now];
    int mid = (l+r)/2;
    A L = query(l,mid,now*2,ll,rr);
    A R = query(mid+1,r,now*2+1,ll,rr);
    A ret;
    if(L.ans == 1e9)    return R;
    if(R.ans == 1e9)    return L;
    ret.v = L.v+R.v;
    ret.l = min(L.l,L.v+R.l);
    ret.r = min(R.r,R.v+L.r);
    ret.ans = max(L.ans,max(R.ans,ret.v-L.l-R.r));
    return ret;
}
int main(){
    int n,m,u,v;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build(1,n,1);
    while(m--){
        scanf("%d %d",&u,&v);
        u++,v++;
        printf("%d\n",max(query(1,n,1,u,v).ans,0));
    }
	return 0;
}