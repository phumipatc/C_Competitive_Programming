/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 10000019
using namespace std;
struct A{
    long long a[2][2];
    A operator * (const A&o) const{
        A temp;
        for(long long i=0;i<2;i++){
            for(long long j=0;j<2;j++){
                temp.a[i][j] = 0;
                for(long long k=0;k<2;k++){
                    temp.a[i][j]+=(a[i][k]*o.a[k][j]);
                    temp.a[i][j]%=MOD;
                }
            }
        }
        return temp;
    }
};
A p[42],ans;
int main(){
    long long q,n;
    p[0].a[0][0] = p[0].a[0][1] = p[0].a[1][0] = 1;
    for(long long i=1;i<=40;i++)
        p[i] = p[i-1]*p[i-1];
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        ans = {1,0,0,1};
        for(int i=40;i>=0;i--){
            if(n&(1ll<<i)){
                ans = ans*p[i];
            }
        }
        printf("%lld\n",ans.a[0][1]);
    }
	return 0;
}
