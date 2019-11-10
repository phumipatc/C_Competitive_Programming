/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
struct matrix{
    long long a[2][2];
    matrix operator *(const matrix &o) const{
        matrix temp;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                temp.a[i][j]=0;
                for(int k=0;k<2;k++){
                    temp.a[i][j]+=a[i][k]*o.a[k][j];
                    temp.a[i][j]%=mod;
                }
            }
        }
        return temp;
    }
};
matrix fibo={1,1,1,0},ans;
void power(long long n){
    if(n==1){
        ans=fibo;
        return ;
    }
    power(n/2);
    ans=ans*ans;
    if(n%2)  ans=ans*fibo;
    return ;
}
long long gcd(long long a,long long b){
    if(a%b==0)  return b;
    else        return gcd(b,a%b);
}
int main()
{
    int q;
    scanf("%d",&q);
    while(q--){
        long long n,m;
        scanf("%lld %lld",&n,&m);
        ans=fibo;
        power(gcd(n,m));
        printf("%lld\n",ans.a[0][1]);
    }
    return 0;
}
