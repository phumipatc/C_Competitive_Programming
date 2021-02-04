/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long l,r,v;
};
A opr[100100];
long long a[100100],tree[400100],lazy[400100],mark[100100],idx,n;
void build(long long l,long long r,long long now){
    if(l == r){
        tree[now] = a[idx++];
        return ;
    }
    long long mid = (l+r)/2;
    build(l,mid,now*2);
    build(mid+1,r,(now*2)+1);
    tree[now] = tree[now*2]+tree[(now*2)+1];
}
void update(long long l,long long r,long long ll,long long rr,long long now,long long v){
    if(lazy[now]){
        tree[now]+=(r-l+1)*lazy[now];
        if(l!=r){
            lazy[now*2]+=lazy[now];
            lazy[(now*2)+1]+=lazy[now];
        }
        lazy[now] = 0;
    }
    if(l>rr || r<ll)    return ;
    if(ll<=l && r<=rr){
        tree[now]+=(r-l+1)*v;
        if(l!=r){
            lazy[now*2]+=v;
            lazy[(now*2)+1]+=v;
        }
        return ;
    }
    long long mid = (l+r)/2;
    update(l,mid,ll,rr,now*2,v);
    update(mid+1,r,ll,rr,(now*2)+1,v);
    tree[now] = tree[now*2]+tree[(now*2)+1];
}
void query(long long l,long long r,long long now){
    if(lazy[now]){
        tree[now]+=(r-l+1)*lazy[now];
        if(l!=r){
            lazy[now*2]+=lazy[now];
            lazy[(now*2)+1]+=lazy[now];
        }
        lazy[now] = 0;
    }
    if(l == r){
        printf("%lld ",tree[now]);
        return ;
    }
    long long mid = (l+r)/2;
    query(l,mid,now*2);
    query(mid+1,r,(now*2)+1);
}
int main(){
    long long n,m,k,l,r,v;
    scanf("%lld %lld %lld",&n,&m,&k);
    for(long long i=0;i<n;i++)
        scanf("%lld",&a[i]);
    build(1,n,1);
    for(long long i=1;i<=m;i++)
        scanf("%lld %lld %lld",&opr[i].l,&opr[i].r,&opr[i].v);
    for(long long i=1;i<=k;i++){
        scanf("%lld %lld",&l,&r);
        mark[l]++;
        mark[r+1]--;
    }
    for(long long i=1;i<=m;i++){
        mark[i]+=mark[i-1];
        if(!mark[i] || !opr[i].v)   continue;
        update(1,n,opr[i].l,opr[i].r,1,opr[i].v*mark[i]);
    }
    query(1,n,1);
    return 0;
}
