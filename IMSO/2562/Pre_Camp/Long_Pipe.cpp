/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD (long long )(1e9+7)
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
A p[32],ans;
int main(){
    long long n;
    scanf("%lld",&n);
    p[0] = {1,1,1,2,1,0,1,0,1};
    for(long long i=1;i<=31;i++)
        p[i] = p[i-1]*p[i-1];
    ans = {1,0,0,0,1,0,0,0,1};
    n++;
    for(long long i=0;i<=31;i++){
        if(!(n&(1ll<<i))) continue;
        ans = ans*p[i];
    }
    printf("%lld\n",(ans.a[1][1]%MOD+(2*ans.a[0][1])%MOD)%MOD);
	return 0;
}