/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 9901
using namespace std;
struct A{
    long long pos,val;
};
A a[1005];
long long countt[1005],fac[1005],inv[1005];
int main(){
    fac[0] = fac[1] = 1;
    inv[0] = inv[1] = 1;
    for(long long i=2;i<=1000;i++){
        fac[i]=(fac[i-1]*i)%MOD;
        for(long long j=1;j<=9901;j++){
            if((fac[i]*j)%MOD == 1){
                inv[i] = j;
                break;
            }
        }
    }
    long long q,n,m,idx,num,ans;
    scanf("%lld",&q);
    while(q--){
        ans = 1;
        scanf("%lld %lld",&n,&m);
        for(long long i=0;i<n;i++){
            scanf("%lld",&countt[i]);
            if(i>0) countt[i]+=countt[i-1];
        }
        a[0] = {1,1};
        for(long long i=1;i<=m;i++){
            scanf("%lld",&idx);
            num = lower_bound(countt,countt+n,idx)-countt+1;
            a[i] = {idx,num};
        }
        a[m+1] = {countt[n-1],n};
        for(long long i=1;i<=m+1;i++){
            idx = a[i].pos-a[i-1].pos;
            num = a[i].val-a[i-1].val;
            ans*=(fac[idx]*inv[num]*inv[idx-num]);
            ans%=MOD;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
