/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int sum=0;
long long l,r;
long long num(int n){
    if(n<=1) return 1;
    return 2*num(n/2)+1;
}
void meltdown(int n,int ll,int rr){
    if(rr<l) return;
    if(ll>r) return;
    if(n<=1){
        sum+=n;
        return ;
    }
    long long len=num(n/2);
    meltdown(n/2,ll,ll+len-1);
    meltdown(n%2,ll+len,ll+len);
    meltdown(n/2,ll+len+1,rr);
}
int main()
{
    int n;
    long long nlen;
    scanf("%d %lld %lld",&n,&l,&r);
    nlen=num(n);
    meltdown(n,1,nlen);
    printf("%d",sum);
    return 0;
}
