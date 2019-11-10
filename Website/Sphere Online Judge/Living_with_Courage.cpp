/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long tree[400100][2],a[100100],idx = 1;
void build(long long l,long long r,long long now){
    if(l == r){
        tree[now][0] = a[idx];
        tree[now][1] = a[idx];
        idx++;
        return ;
    }
    long long mid = (l+r)/2;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    tree[now][0] = tree[now*2][0] + tree[now*2+1][0];
    tree[now][1] = min(tree[now*2][1],tree[now*2+1][1]);
}
void update(long long l,long long r,long long now,long long idx,long long v){
    if(l == r && l == idx){
        tree[now][0]+=v;
        tree[now][1]+=v;
        return ;
    }
    if(l>idx || r<idx)  return ;
    long long mid = (l+r)/2;
    update(l,mid,now*2,idx,v);
    update(mid+1,r,now*2+1,idx,v);
    tree[now][0] = tree[now*2][0]+tree[now*2+1][0];
    tree[now][1] = min(tree[now*2][1],tree[now*2+1][1]);
}
long long minn;
long long query(long long l,long long r,long long now,long long ll,long long rr){

    if(l>rr || r<ll)    return 0;
    if(ll<=l && r<=rr){
        minn = min(minn,tree[now][1]);
        return tree[now][0];
    }
    long long mid = (l+r)/2;
    long long q1 = query(l,mid,now*2,ll,rr);
    long long q2 = query(mid+1,r,now*2+1,ll,rr);
    return q1+q2;
}
char str[10];
int main(){
    long long n,m,l,r;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    build(1,n,1);
    scanf("%lld",&m);
    while(m--){
        scanf(" %s %lld %lld",str,&l,&r);
        if(str[0] == 'E'){
            update(1,n,1,r+1,-l);
        }else if(str[0] == 'G'){
            update(1,n,1,r+1,l);
        }else{
            minn = 1e9;
            printf("%lld\n",query(1,n,1,l+1,r+1)-minn);
        }
    }
    return 0;
}
