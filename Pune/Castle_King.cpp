#include<bits/stdc++.h>
using namespace std;
long long a[500100];
int main(){
	long long n,sum;
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	sum = a[1]+a[n];
	for(long long i=1;i<=n;i++){
		sum+=(2*a[i])+1;
		if(a[i+1]>a[i])	sum+=(a[i+1]-a[i]);
	}
	printf("%lld\n",sum);
	return 0;
}