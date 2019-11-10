/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
	int q;
	scanf("%d",&q);
	for (int i=1; i<=q; i++) {
		long long n, k;
		scanf("%lld %lld",&n,&k);
		long long binary=1;
		while(binary*2<=k)  binary *= 2;
		long long sum=n-binary+1;
		long long a=sum/binary;
		if((n+1)%binary>k-binary) a++;
		printf("Case #%d: %lld %lld\n",i,a/2,(a-1)/2);
	}
	return 0;
}
