/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
struct A{
    long long a[3][3];
    A operator * (const A&o) const{
        A temp;
        for(long long i=0;i<3;i++){
            for(long long j=0;j<3;j++){
                temp.a[i][j] = 0;
                for(long long k=0;k<3;k++){
                    temp.a[i][j]+=a[i][k]*o.a[k][j];
                    temp.a[i][j]%=MOD;
                }
            }
        }
        return temp;
    }
};
A p[42],ans;
int main(){
    p[0] = {{0,1,0,0,0,1,6,5,-2}};
    for(long long i=1;i<40;i++)
        p[i] = p[i-1]*p[i-1];
    A ans;
    long long q;
    scanf("%lld",&q);
    for(long long k=1;k<=q;k++){
        ans={{1,0,0,0,1,0,0,0,1}};
        long long n;
        scanf("%lld",&n);
        for(long long i=0;i<40;i++)
            if(n&(1ll<<i))
                ans = ans * p[i];
        printf("Case #%lld: %lld\n",k,((((14*ans.a[0][0])+(15*ans.a[0][1])+(63*ans.a[0][2]))%MOD)+MOD)%MOD);
    }
	return 0;
}
