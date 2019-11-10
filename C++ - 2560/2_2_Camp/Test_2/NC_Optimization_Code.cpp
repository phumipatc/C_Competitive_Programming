/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
struct A{
    long long a[3][3];
};
A temp;
A multi(A a,A b){
    memset(temp.a,0,sizeof temp.a);
    for(long long i=0;i<3;i++){
        for(long long j=0;j<3;j++){
            for(long long k=0;k<3;k++){
                temp.a[i][j]+=a.a[i][k]*b.a[k][j];
                temp.a[i][j]%=MOD;
            }
        }
    }
    return temp;
}
A a[40];
int main(){
    a[0]={{0,1,0,0,0,1,6,5,-2}};
    for(long long i=1;i<40;i++)
        a[i]=multi(a[i-1],a[i-1]);
    A ans;
    long long q;
    scanf("%lld",&q);
    for(long long k=1;k<=q;k++){
        ans={{1,0,0,0,1,0,0,0,1}};
        long long n;
        scanf("%lld",&n);
        for(long long i=0;i<40;i++)
            if(n&(1ll<<i))
                ans=multi(ans,a[i]);
        printf("Case #%lld: %lld\n",k,((((14*ans.a[0][0])+(15*ans.a[0][1])+(63*ans.a[0][2]))%MOD)+MOD)%MOD);
    }
    return 0;
}
