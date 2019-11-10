/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long pos,val;
};
map<long long ,long long > mapp;
vector<long long > p;
A a[100005];
long long b[100005];
long long tree[400100];
void update(long long l,long long r,long long now,long long idx,long long v){
    if(l>idx || r<idx)  return ;
    if(l == r){
        tree[now] = v;
        return ;
    }
    long long mid = (l+r)/2;
    update(l,mid,now*2,idx,v);
    update(mid+1,r,(now*2)+1,idx,v);
    tree[now] = max(tree[now*2],tree[(now*2)+1]);
}
long long query(long long l,long long r,long long ll,long long rr,long long now){
    if(l>rr || r<ll)    return -1e18;
    if(l>=ll && r<=rr)  return tree[now];
    long long mid = (l+r)/2;
    return max(query(l,mid,ll,rr,now*2),query(mid+1,r,ll,rr,(now*2)+1));
}
int main(){
    long long n,k,s,idx = 1,ans = 0,l,r,maxx;
    scanf("%lld %lld %lld",&n,&k,&s);
    for(long long i=1;i<=400000;i++)  tree[i] = -1e18;
    for(long long i=1;i<=n;i++){
        scanf("%lld %lld",&a[i].pos,&a[i].val);
        b[i] = a[i].pos;
    }
    b[0] = s;
    sort(b,b+n+1);
    for(long long i=0;i<=n;i++){
        if(b[i] == b[i+1])  continue;
        mapp[b[i]] = idx++;
        p.push_back(b[i]);
    }
    idx--;
    update(1,idx,1,mapp[s],0);
    for(long long i=1;i<=n;i++){
        l = lower_bound(p.begin(),p.end(),a[i].pos-k)-p.begin();
        r = upper_bound(p.begin(),p.end(),a[i].pos+k)-p.begin()-1;
        maxx = query(1,idx,l+1,r+1,1);
        if(maxx == -1e18) continue;
        update(1,idx,1,mapp[a[i].pos],maxx+a[i].val);
        ans = max(ans,maxx+a[i].val);
    }
    printf("%lld\n",ans);
    return 0;
}
