/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long l,r,v,ans;
};
A tree[200100];
long long a[50100],idx = 1;
void build(long long l,long long r,long long now){
    if(l == r){
        tree[now].v = a[idx++];
        tree[now].l = tree[now].r = tree[now].ans = tree[now].v;
        return ;
    }
    long long mid = (l+r)/2;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    tree[now].v = tree[now*2].v+tree[now*2+1].v;
    tree[now].l = max(tree[now*2].l,tree[now*2].v+tree[now*2+1].l);
    tree[now].r = max(tree[now*2+1].r,tree[now*2].r+tree[now*2+1].v);
    tree[now].ans = max(tree[now].v,tree[now*2].v+tree[now*2+1].v);
    tree[now].ans = max(tree[now].ans,tree[now*2].v);
    tree[now].ans = max(tree[now].ans,tree[now*2+1].v);
    tree[now].ans = max(tree[now].ans,tree[now].l);
    tree[now].ans = max(tree[now].ans,tree[now*2].r+tree[now*2+1].l);
    tree[now].ans = max(tree[now].ans,tree[now].r);
    tree[now].ans = max(tree[now].ans,max(tree[now*2].ans,tree[now*2+1].ans));
}
A query(long long l,long long r,long long now,long long ll,long long rr){
    if(r<ll || l>rr)    return {-1<<30,-1<<30,0,-1<<30};
    if(ll<=l && r<=rr)  return tree[now];
    long long mid = (l+r)/2;
    A temp,q1 = query(l,mid,now*2,ll,rr),q2 = query(mid+1,r,now*2+1,ll,rr);
    if(q1.ans == -1<<30)    return q2;
    if(q2.ans == -1<<30)    return q1;
    temp.v = q1.v+q2.v;
    temp.l = max(q1.l,q1.v+q2.l);
    temp.r = max(q2.r,q1.r+q2.v);
    temp.ans = max(temp.v,q1.v+q2.v);
    temp.ans = max(temp.ans,q1.v);
    temp.ans = max(temp.ans,q2.v);
    temp.ans = max(temp.ans,temp.l);
    temp.ans = max(temp.ans,q1.r+q2.l);
    temp.ans = max(temp.ans,temp.r);
    temp.ans = max(temp.ans,max(q1.ans,q2.ans));
    return temp;
}
int main(){
    long long n,m,l,r;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    build(1,n,1);
    scanf("%lld",&m);
    while(m--){
        scanf("%lld %lld",&l,&r);
        printf("%lld\n",query(1,n,1,l,r).ans);
    }
    return 0;
}
