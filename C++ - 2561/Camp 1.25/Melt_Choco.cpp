/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long l,r,ans = 0;
long long num(long long n){
    if(n<=1)    return 1;
    else        return 2*num(n/2)+1;
}
void melt(long long n,long long ll,long long rr){
    if(ll>r || rr<l)    return ;
    if(n == 0 || n == 1){
        ans+=n;
        return ;
    }
    long long mid = num(n/2);
    melt(n/2,ll,ll+mid-1);
    melt(n%2,ll+mid,ll+mid);
    melt(n/2,ll+mid+1,rr);
}
int main(){
    long long n;
    scanf("%lld %lld %lld",&n,&l,&r);
    melt(n,1,num(n));
    printf("%lld\n",ans);
	return 0;
}
