/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 2553
using namespace std;
struct A{
    long long a[4][4];
    A operator * (const A&o){
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
    }
};
A p[60],ans;
int main(){
    long long a,b,c,d,e,f,g,h;
    scanf("%lld %lld %lld %lld %lld %lld %lld %lld",&a,&b,&c,&d,&e,&f,&g,&h);
    p[0] = {e,f,g,h,1,0,0,0,0,1,0,0,0,0,1,0};
    for(long long i=1;i<=59;i++)
        p[i] = p[i-1]*p[i-1];
    long long q,n;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
    }
	return 0;
}
