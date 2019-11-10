/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1010],fact[1010],tree[1010];
void update(long long idx,long long v){
    while(idx<=1002){
        tree[idx]+=v;
        idx+=idx&(-idx);
    }
}
long long query(long long idx){
    long long sum = 0;
    while(idx>0){
        sum+=tree[idx];
        idx-=idx&(-idx);
    }
    return sum;
}
int main(){
    long long n,q,num,now,ans;
    scanf("%lld %lld",&n,&q);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    while(q--){
        scanf("%lld",&num);
        fact[0] = fact[1] = 1,ans = 0;
        for(long long i=2;i<=n;i++)
            fact[i] = (fact[i-1]*i)%num;
        memset(tree,0,sizeof tree);
        for(long long i=1;i<n;i++){
            now = a[i]-query(a[i]-1);
            ans = (ans+((now-1)*fact[n-i]))%num;
            update(a[i],1);
        }
        printf("%lld\n",(ans+1)%num);
    }
	return 0;
}
