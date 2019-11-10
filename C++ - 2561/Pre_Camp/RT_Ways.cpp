/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 10000019
using namespace std;
struct A{
    long long a[4][4];
    A operator * (const A&o) const{
        A temp;
        for(long long i=0;i<4;i++){
            for(long long j=0;j<4;j++){
                temp.a[i][j] = 0;
                for(long long k=0;k<4;k++){
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
    long long q,n;
    p[0] = {0,0,1,0,1,0,1,0,0,0,0,1,0,1,0,0};
    for(long long i=1;i<=40;i++)
        p[i] = p[i-1]*p[i-1];
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        ans = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
        n--;
        for(long long i=0;i<=40;i++){
            if((1ll<<i) & n)
                ans = ans*p[i];
        }
        for(int i=0;i<4;i++)
            printf("%lld ",ans.a[i][0]);
        printf("\n");
    }
	return 0;
}
