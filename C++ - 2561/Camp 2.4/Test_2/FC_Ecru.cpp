/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
struct A{
    string str;
    bool operator < (const A&o) const{
        return str<o.str;
    }
};
A a[3010];
long long fact[3010];
long long place(long long l,long long r,long long len){
	if(l == r)					return 1;
	if(len>a[l].str.length())	return fact[r-l+1];
	string temp = a[l].str.substr(0,len);
	long long st = l,countt = 0,ans = 1;
	for(long long i=l+1;i<=r;i++){
		if(a[i].str.length()<len || a[i].str.substr(0,len)!=temp){
			ans*=place(st,i-1,len+1);
			ans%=MOD;
			st = i,countt++;
			temp = a[i].str.substr(0,len);
		}
	}
	if(st!=r){
		ans*=place(st,r,len+1);
		ans%=MOD;
		countt++;
	}
	// printf("%lld %lld %lld %lld %lld\n",l,r,len,countt,ans);
	return (ans*fact[countt])%MOD;
}
int main(){
	fact[0] = 1;
    for(long long i=1;i<=3000;i++)
        fact[i] = (fact[i-1]*i)%MOD;
    long long n;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)
        cin >> a[i].str;
    sort(a+1,a+n+1);
    printf("%lld\n",place(1,n,0));
	return 0;
}
