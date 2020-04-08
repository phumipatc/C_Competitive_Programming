/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct A{
	LL h,v;
	bool operator < (const A&o) const{
		return v<o.v;
	}
};
A a[500010];
LL l[500010],r[500010];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	LL n,minn = 1e18,sum,pos;
	cin >> n;
	for(LL i=1;i<=n;i++)
		cin >> a[i].h;
	for(LL i=1;i<=n;i++)
		cin >> a[i].v;
	sort(a+1,a+n+1);
	for(LL i=n;i>=1;i--)
		r[i] = r[i+1]+a[i].v;
	for(LL i=1;i<=n;i++){
		sum = l[i-1]+r[i+1]-((n-1)*a[i].v);
		if(sum<minn){
			minn = sum;
			pos = a[i].v;
		}
		l[i] = l[i-1]+a[i].v+a[i].h;
	}
	cout << pos << ' ' << minn << '\n';
	return 0;
}