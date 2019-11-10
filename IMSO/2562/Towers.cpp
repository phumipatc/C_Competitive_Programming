/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,l,r,num;
};
A tree[800010];
int lazy[800010];
void build(int l,int r,int now){
    if(l == r){
        tree[now] = {0,l,r,1};
        return ;
    }
    int mid = (l+r)/2;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    tree[now] = {0,l,r,1};
}
void update(int l,int r,int now,int ll,int rr,int v){
    if(lazy[now]){
        tree[now].v+=lazy[now];
        if(l!=r)    lazy[now*2]+=lazy[now],lazy[now*2+1]+=lazy[now];
        lazy[now] = 0;
    }
    if(r<ll || l>rr)    return ;
    if(l>=ll && r<=rr){
        tree[now].v+=v;
        if(l!=r)    lazy[now*2]+=v,lazy[now*2+1]+=v;
        return ;
    }
    int mid = (l+r)/2;
    update(l,mid,now*2,ll,rr,v);
    update(mid+1,r,now*2+1,ll,rr,v);
    A L = tree[now*2],R = tree[now*2+1];
    if(L.v>R.v){
        tree[now] = L;
    }else if(L.v<R.v){
        tree[now] = R;
    }else{
        tree[now].v = L.v;
        if(L.r+1 == R.l)    tree[now].num = L.num+R.num-1;
        else                tree[now].num = L.num+R.num;
        tree[now].l = L.l;
        tree[now].r = R.r;
    }
}
int main(){
    int n,m,l,r,v;
    scanf("%d %d",&n,&m);
    build(1,n,1);
    while(m--){
        scanf("%d %d %d",&l,&r,&v);
        update(1,n,1,l,r,v);
        printf("%d %d\n",tree[1].v,tree[1].num);
    }
	return 0;
}