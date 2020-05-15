/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD (long long )(1e9+7)
using namespace std;
struct A{
    long long num,pos;
    bool operator < (const A&o) const{
        return num<o.num;
    }
};
A a[500010];
long long tree[500010][2];
void upd(long long idx,long long v,long long now){
    while(idx<=500003){
        tree[idx][now]+=v;
        tree[idx][now]%=MOD;
        idx+= idx & -idx;
    }
}
long long query(long long idx,long long now){
    long long sum = 0;
    while(idx>0){
        sum+=tree[idx][now];
        sum%=MOD;
        idx-= idx & -idx;
    }
    return sum;
}
int main(){
    long long n;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i].num);
        a[i].pos = i;
    }
    sort(a+1,a+n+1);
    long long ans = 0;
    for(long long i=1;i<=n;i++){
        upd(a[i].pos,a[i].pos,0);
        upd(a[i].pos,n-a[i].pos+1,1);
        ans+=(((a[i].num*query(a[i].pos,0))%MOD)*(n-a[i].pos+1))%MOD;
        ans%=MOD;
        ans+=(((a[i].num*((query(n,1)-query(a[i].pos,1)+MOD)%MOD))%MOD)*a[i].pos)%MOD;
        ans%=MOD;
    }
    printf("%lld\n",ans);
	return 0;
}