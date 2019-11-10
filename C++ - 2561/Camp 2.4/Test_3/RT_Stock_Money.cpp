/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 100000007
using namespace std;
struct A{
    long long a[5][5];
    A operator * (const A&o) const{
        A temp;
        for(long long i=0;i<5;i++){
            for(long long j=0;j<5;j++){
                temp.a[i][j] = 0;
                for(long long k=0;k<5;k++){
                    temp.a[i][j]+=a[i][k]*o.a[k][j];
                    temp.a[i][j]%=MOD;
                }
            }
        }
        return temp;
    }
};
A ans,p[20],mul;
int main(){
    long long n,m,l,k,last;
    scanf("%lld %lld",&n,&m);
    last = m;
    for(long long i=0;i<m;i++)
        scanf("%lld",&ans.a[i][0]);
    while(n--){
        scanf("%lld %lld",&l,&k);
        memset(mul.a,0,sizeof mul.a);
        memset(p[0].a,0,sizeof p[0].a);
        for(long long i=0;i<l;i++)
            for(long long j=0;j<last;j++)
                scanf("%lld",&mul.a[i][j]);
        last = l;
        for(long long i=0;i<l;i++)
            for(long long j=0;j<l;j++)
                scanf("%lld",&p[0].a[i][j]);
        for(long long i=1;i<=18;i++)
            p[i] = p[i-1]*p[i-1];
        ans = mul*ans;

        for(long long i=0;i<=18;i++)
            if(k & (1ll<<i))
                ans = p[i]*ans;
    }
    for(long long i=0;i<last;i++){
        printf("%lld ",ans.a[i][0]);
    }
    return 0;
}
