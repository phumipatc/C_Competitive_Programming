/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
struct A{
    long long a[2][2];
    A operator * (const A&o) const{
        A temp;
        for(long long i=0;i<2;i++){
            for(long long j=0;j<2;j++){
                temp.a[i][j] = 0;
                for(long long k=0;k<2;k++){
                    temp.a[i][j] += (a[i][k]*o.a[k][j]);
                    temp.a[i][j]%=MOD;
                }
            }
        }
        return temp;
    }
};
A p[32],ans;
long long GCD(long long a,long long b){
    if(a%b == 0)    return b;
    else            return GCD(b,a%b);
}
int main(){
    long long q,n,m,now;
    scanf("%lld",&q);
    p[0] = {1,1,1,0};
    for(long long i=1;i<=30;i++)
        p[i] = p[i-1]*p[i-1];
    // printf("%lld %lld\n%lld %lld\n",p[1].a[0][0],p[1].a[0][1],p[1].a[1][0],p[1].a[1][1]);
    while(q--){
        scanf("%lld %lld",&n,&m);
        if(n>m) swap(n,m);
        ans = {1,0,0,1};
        now = GCD(m,n);
        for(long long i=0;i<=30;i++){
            if(1ll<<i & now)
                ans = ans*p[i];
        }
        printf("%lld\n",ans.a[0][1]);
    }
	return 0;
}
