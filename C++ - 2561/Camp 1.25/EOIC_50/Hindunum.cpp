/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long bit[20];
int main(){
    long long n,num;
    scanf("%lld",&n);
    for(long long i=0;i<n;i++){
        scanf("%lld",&num);
        for(long long j=0;j<20;j++)
            if(num & (1<<j))
                bit[j]++;
    }
    long long ans = 0;
    for(long long i=0;i<20;i++)
        ans+=bit[i]*(n-bit[i])*(1<<i);
    printf("%lld\n",ans);
	return 0;
}
