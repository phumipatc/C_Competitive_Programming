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
    A operator * (const A&o){
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
A p[60],ans;
int main(){
    long long q,n;
    p[0] = {1,1,0,1,0,0,0,1,0};
    for(long long i=1;i<=59;i++)
        p[i] = p[i-1]*p[i-1];
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //         printf("%lld ",p[1].a[i][j]);
    //     }
    //     cout << endl;
    // }
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        ans = {1,0,0,0,1,0,0,0,1};
        for(long long i=0;i<=59;i++){
            if(n & (1ll<<i)){
                ans = ans*p[i];
            }
        }
        printf("%lld\n",ans.a[0][1]);
    }
	return 0;
}
