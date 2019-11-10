/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL tree[800010][2];
void build(LL l,LL r,LL now){
    if(l == r){
        tree[now][0] = -l;
        tree[now][1] = l;
        return ;
    }
    LL mid = (l+r)/2;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    tree[now][0] = max(tree[now*2][0],tree[now*2+1][0]);
    tree[now][1] = max(tree[now*2][1],tree[now*2+1][1]);
}
void update(LL l,LL r,LL now,LL idx,LL v,LL type){
    if(l>idx || r<idx)	return ;
    if(l == r){
        tree[now][type] = max(tree[now][type],v);
        return ;
    }
    LL mid = (l+r)/2;
    update(l,mid,now*2,idx,v,type);
    update(mid+1,r,now*2+1,idx,v,type);
    tree[now][type] = max(tree[now*2][type],tree[now*2+1][type]);
}
LL query(LL l,LL r,LL now,LL ll,LL rr,LL type){
    if(r<ll || l>rr)	return (LL )-1e9;
    if(l>=ll && r<=rr)	return tree[now][type];
    LL mid = (l+r)/2;
    // printf("%lld %lld %lld %lld %lld\n",l,r,type,query(l,mid,now*2,ll,rr,type),query(mid+1,r,now*2+1,ll,rr,type));
    return max(query(l,mid,now*2,ll,rr,type),query(mid+1,r,now*2+1,ll,rr,type));
}
int main(){
    // ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    LL n,m,u,v,w,ru,rv,maxx = 0;
    scanf("%lld %lld",&n,&m);
    build(1,n,1);
    for(LL i=1;i<=m;i++){
        scanf("%lld %lld %lld",&u,&v,&w);
        ru = w+max(query(1,n,1,1,u,1)-u,query(1,n,1,u,n,0)+u);
        rv = w+max(query(1,n,1,1,v,1)-v,query(1,n,1,v,n,0)+v);
        // printf("%lld %lld %lld\n",ru,query(1,n,1,1,u,1)-u,query(1,n,1,u,n,0)+u);
        // printf("%lld %lld %lld\n",rv,query(1,n,1,1,v,1)-v,query(1,n,1,v,n,0)+v);
        maxx = max(maxx,max(ru,rv));
        update(1,n,1,v,ru-v,0);
        update(1,n,1,v,ru+v,1);
        update(1,n,1,u,rv-u,0);
        update(1,n,1,u,rv+u,1);
        printf("%lld\n",maxx);
    }
    return 0;
}