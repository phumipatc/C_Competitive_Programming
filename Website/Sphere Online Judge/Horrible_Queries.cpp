/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long tree[400100],lazy[400100];
void update(long long l,long long r,long long ll,long long rr,long long now,long long v){
    if(lazy[now]){
        tree[now]+=(lazy[now]*(r-l+1));
        if(l!=r){
            lazy[now*2]+=lazy[now];
            lazy[(now*2)+1]+=lazy[now];
        }
        lazy[now] = 0;
    }
    if(l>rr || r<ll)    return ;
    if(l>=ll && r<=rr){
        tree[now]+=(v*(r-l+1));
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
long long query(long long l,long long r,long long ll,long long rr,long long now){
    if(lazy[now]){
        tree[now]+=(lazy[now]*(r-l+1));
        if(l!=r){
            lazy[now*2]+=lazy[now];
            lazy[(now*2)+1]+=lazy[now];
        }
        lazy[now] = 0;
    }
    if(l>rr || r<ll)    return 0;
    if(ll<=l && r<=rr)  return tree[now];
    long long mid = (l+r)/2;
    long long ans = query(l,mid,ll,rr,now*2)+query(mid+1,r,ll,rr,(now*2)+1);
    tree[now] = tree[now*2]+tree[(now*2)+1];
    return ans;
}
int main(){
    long long q,n,c,opr,l,r,v;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld",&n,&c);
        memset(tree,0,sizeof tree);
        memset(lazy,0,sizeof lazy);
        while(c--){
            scanf("%lld %lld %lld",&opr,&l,&r);
            if(opr == 0){
                scanf("%lld",&v);
                update(1,n,l,r,1,v);
            }else{
                printf("%lld\n",query(1,n,l,r,1));
            }
        }
    }
    return 0;
}
