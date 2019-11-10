/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long pos,v;
};
A a[100010];
long long tree[400010];
long long st;
vector<long long > comp;
set<long long > sett;
void build(long long l,long long r,long long now){
    if(l == r){
        if(l == st) tree[now] = 0;
        else        tree[now] = -1e9;
        return ;
    }
    long long mid = (l+r)/2;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    tree[now] = max(tree[now*2],tree[now*2+1]);
}
void update(long long l,long long r,long long now,long long idx,long long v){
    if(l>idx || r<idx)  return ;
    if(l == r){
        tree[now] = v;
        return ;
    }
    long long mid = (l+r)/2;
    update(l,mid,now*2,idx,v);
    update(mid+1,r,now*2+1,idx,v);
    tree[now] = max(tree[now*2],tree[now*2+1]);
}
long long query(long long l,long long r,long long now,long long ll,long long rr){
    if(l>rr || r<ll)    return -1e9;
    if(ll<=l && r<=rr)  return tree[now];
    long long mid = (l+r)/2;
    return max(query(l,mid,now*2,ll,rr),query(mid+1,r,now*2+1,ll,rr));
}
int main(){
    long long n,m,l,r,temp,now;
    scanf("%lld %lld %lld",&n,&m,&st);
    sett.insert(st);
    for(long long i=1;i<=n;i++){
        scanf("%lld %lld",&a[i].pos,&a[i].v);
        sett.insert(a[i].pos);
    }
    for(auto x:sett)
        comp.push_back(x);
    st = lower_bound(comp.begin(),comp.end(),st)-comp.begin()+1;
    build(1,comp.size(),1);
    for(long long i=1;i<=n;i++){
        l = lower_bound(comp.begin(),comp.end(),a[i].pos-m)-comp.begin()+1;
        r = upper_bound(comp.begin(),comp.end(),a[i].pos+m)-comp.begin();
        now = lower_bound(comp.begin(),comp.end(),a[i].pos)-comp.begin()+1;
        temp = query(1,comp.size(),1,l,r);
        // printf("%lld %lld %lld %lld\n",l,r,now,temp);
        if(temp == -1e9)    continue;
        update(1,comp.size(),1,now,temp+a[i].v);
    }
    printf("%lld\n",query(1,comp.size(),1,1,comp.size()));
	return 0;
}