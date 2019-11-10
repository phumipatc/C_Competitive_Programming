/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long n,c;
struct A{
    long long a[6][6];
    A operator * (const A&o) const{
        A temp;
        for(long long i=0;i<n;i++){
            for(long long j=0;j<n;j++){
                temp.a[i][j] = 0;
                for(long long k=0;k<n;k++){
                    temp.a[i][j]+=(a[i][k]*o.a[k][j]);
                    temp.a[i][j]%=c;
                }
            }
        }
        return temp;
    }
};
A p[62],temp,ans;
int main(){
    long long b;
    scanf("%lld",&n);
    for(long long i=0;i<n;i++)
        for(long long j=0;j<n;j++)
            scanf("%lld",&p[0].a[i][j]);
    scanf("%lld %lld",&b,&c);
    for(long long i=1;i<=60;i++)
        p[i] = p[i-1]*p[i-1];
    for(long long i=0;i<n;i++)
        ans.a[i][i] = 1;
    for(long long i=60;i>=0;i--){
        if(b&(1ll<<i)){
            ans = ans*p[i];
        }
    }
    for(long long i=0;i<n;i++){
        for(long long j=0;j<n;j++){
            printf("%lld ",ans.a[i][j]);
        }
        printf("\n");
    }
	return 0;
}
