/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 6427
using namespace std;
struct A{
    long long a[2][2];
    A operator * (const A&o) const{
        A temp;
        for(long long i=0;i<2;i++){
            for(long long j=0;j<2;j++){
                temp.a[i][j] = 0;
                for(long long k=0;k<2;k++){
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
    p[0] = {1,1,1,0};
    for(long long i=1;i<=40;i++)
        p[i] = p[i-1]*p[i-1];
    // printf("%lld %lld\n%lld %lld\n",p[1].a[0][0],p[1].a[0][1],p[1].a[1][0],p[1].a[1][1]);
    long long n;
    scanf("%lld",&n);
    ans = {1,0,0,1};
    for(long long i=0;i<=40;i++){
        if(n & (1ll<<i)){
            ans = ans*p[i];
        }
    }
    // for(int i=0;i<2;i++){
    //     for(int j=0;j<2;j++){
    //         printf("%lld ",ans.a[i][j]);
    //     }
    //     cout << endl;
    // }
    printf("%lld\n",ans.a[0][0]);
	return 0;
}
