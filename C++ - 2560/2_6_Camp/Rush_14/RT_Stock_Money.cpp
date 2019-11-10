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
};
A temp;
A multi(A a,A b){
    memset(temp.a,0,sizeof temp.a);
    for(long long i=0;i<5;i++){
        for(long long j=0;j<5;j++){
            for(long long k=0;k<5;k++){
                temp.a[i][j]+=a.a[i][k]*b.a[k][j];
                temp.a[i][j]%=MOD;
            }
        }
    }
    return temp;
}
A st,p[20],mul;
int main(){
    long long n,m,l,k,last;
    scanf("%lld %lld",&n,&m);
    last = m;
    for(long long i=0;i<m;i++)
        scanf("%lld",&st.a[i][0]);
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
            p[i] = multi(p[i-1],p[i-1]);
        st = multi(mul,st);

        for(long long i=0;i<=18;i++)
            if(k & (1ll<<i))
                st = multi(p[i],st);
    }
    for(long long i=0;i<last;i++){
        printf("%lld ",st.a[i][0]);
    }
    return 0;
}
