/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long num,bit[2][25];
};
A tree[400010];
long long a[100010],lazy[400010];
void build(long long l,long long r,long long now){
    if(l == r){
        tree[now].num = a[l];
        for(long long i=0;i<20;i++){
            if(a[l] & (1<<i))   tree[now].bit[1][i]++;
            else                tree[now].bit[0][i]++;
        }
        return ;
    }
    long long mid = (l+r)/2;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    tree[now].num = 0;
    for(long long i=0;i<20;i++){
        tree[now].bit[0][i] = tree[now*2].bit[0][i] + tree[now*2+1].bit[0][i];
        tree[now].bit[1][i] = tree[now*2].bit[1][i] + tree[now*2+1].bit[1][i];
        tree[now].num+=tree[now].bit[1][i]*(1<<i);
    }
}
void update(long long l,long long r,long long now,long long ll,long long rr,long long v){
    if(lazy[now]){
        tree[now].num = 0;
        for(long long i=0;i<20;i++){
            if((1<<i) & lazy[now])  swap(tree[now].bit[0][i],tree[now].bit[1][i]);
            tree[now].num+=tree[now].bit[1][i]*(1<<i);
        }
        if(l!=r)    lazy[now*2]^=lazy[now],lazy[now*2+1]^=lazy[now];
        lazy[now] = 0;
    }
    if(l>rr || r<ll)    return ;
    if(l>=ll && r<=rr){
        tree[now].num = 0;
        for(long long i=0;i<20;i++){
            if((1<<i) & v)  swap(tree[now].bit[0][i],tree[now].bit[1][i]);
            tree[now].num+=tree[now].bit[1][i]*(1<<i);
        }
        if(l!=r)    lazy[now*2]^=v,lazy[now*2+1]^=v;
        return ;
    }
    long long mid = (l+r)/2;
    update(l,mid,now*2,ll,rr,v);
    update(mid+1,r,now*2+1,ll,rr,v);
    tree[now].num = 0;
    for(long long i=0;i<20;i++){
        tree[now].bit[0][i] = tree[now*2].bit[0][i] + tree[now*2+1].bit[0][i];
        tree[now].bit[1][i] = tree[now*2].bit[1][i] + tree[now*2+1].bit[1][i];
        tree[now].num+=tree[now].bit[1][i]*(1<<i);
    }
}
long long query(long long l,long long r,long long now,long long ll,long long rr){
    if(lazy[now]){
        tree[now].num = 0;
        for(long long i=0;i<20;i++){
            if((1<<i) & lazy[now])  swap(tree[now].bit[0][i],tree[now].bit[1][i]);
            tree[now].num+=tree[now].bit[1][i]*(1<<i);
        }
        if(l!=r)    lazy[now*2]^=lazy[now],lazy[now*2+1]^=lazy[now];
        lazy[now] = 0;
    }
    if(l>rr || r<ll)    return 0;
    if(l>=ll && r<=rr)  return tree[now].num;
    long long mid = (l+r)/2;
    long long ansl = query(l,mid,now*2,ll,rr);
    long long ansr = query(mid+1,r,now*2+1,ll,rr);
    tree[now].num = 0;
    for(long long i=0;i<20;i++){
        tree[now].bit[0][i] = tree[now*2].bit[0][i] + tree[now*2+1].bit[0][i];
        tree[now].bit[1][i] = tree[now*2].bit[1][i] + tree[now*2+1].bit[1][i];
        tree[now].num+=tree[now].bit[1][i]*(1<<i);
    }
    return ansl+ansr;
}
int main(){
    long long n,opr,l,r,num;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    build(1,n,1);
    long long q;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld %lld",&opr,&l,&r);
        if(opr == 1)    printf("%lld\n",query(1,n,1,l,r));
        else{
            scanf("%lld",&num);
            update(1,n,1,l,r,num);
        }
    }
	return 0;
}