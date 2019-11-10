/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
	if(a%b == 0)	return b;
	else			return gcd(b,a%b);
}
int main(){
	freopen("0_in.txt","r",stdin);
	freopen("0_out.txt","w",stdout);
	long long n,GCD,ans = 1,countt,num;
	scanf("%lld %lld",&n,&GCD);
	n--;
	while(n--){
		scanf("%lld",&num);
		GCD = gcd(GCD,num);
	}
	for(long long i=2;i<=sqrt(GCD);i++){
		if(GCD%i!=0)	continue;
		countt = 1;
		while(GCD%i == 0){
			countt++;
			GCD/=i;
		}
		ans*=countt;
	}
	printf("%lld\n",ans);
	return 0;
}
