/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long num,l,r,k;
    bool operator < (const A&o) const{
        return k<o.k;
    }
};
struct B{
    long long pos,v;
    bool operator < (const B&o) const{
        return v<o.v;
    }
};
A Q[200100];
B a[30100];
long long tree[30100],ans[200100];
void update(long long idx,long long v){
    while(idx<=30020){
        tree[idx]+=v;
        idx+=(idx&(-idx));
    }
}
long long query(long long idx){
    long long sum = 0;
    while(idx>0){
        sum+=tree[idx];
        idx-=(idx&(-idx));
    }
    return sum;
}
int main(){
    long long n,idx = 1,now,q;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i].v);
        a[i].pos = i;
    }
    sort(a+1,a+n+1);
    scanf("%lld",&q);
    for(long long i=1;i<=q;i++){
        scanf("%lld %lld %lld",&Q[i].l,&Q[i].r,&Q[i].k);
        Q[i].num = i;
    }
    sort(Q+1,Q+q+1);
    for(long long i=1;i<=q;i++){
        while(a[idx].v<=Q[i].k && idx<=n){
            update(a[idx].pos,1);
            idx++;
        }
        ans[Q[i].num] = (Q[i].r-Q[i].l+1)-(query(Q[i].r)-(query(Q[i].l-1)));
    }
    for(long long i=1;i<=q;i++)   printf("%lld\n",ans[i]);
    return 0;
}
