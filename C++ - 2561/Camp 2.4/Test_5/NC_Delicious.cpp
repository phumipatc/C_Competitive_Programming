/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long LIS[100010];
int main(){
    long long n,idx,maxx = 0,sum = 0,num;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&num);
        sum+=num;
        if(sum<0)   continue;
        idx = lower_bound(LIS,LIS+maxx,sum)-LIS;
        if(idx == maxx) maxx++;
        LIS[idx] = sum;
    }
    printf("%lld\n",idx+1);
	return 0;
}