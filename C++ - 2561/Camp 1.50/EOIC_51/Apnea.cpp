/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,num,sum = 0,maxx = -1e9;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&num);
        sum+=num;
        maxx = max(maxx,num);
    }
    printf("%lld\n",max(2*maxx,sum));
	return 0;
}
