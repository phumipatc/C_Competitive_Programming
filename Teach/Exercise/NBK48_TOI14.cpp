/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[100010];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,q;
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		a[i]+=a[i-1];
	}
	for(int i=n-1;i>=1;i--)
		a[i] = min(a[i],a[i+1]);
	int num;
	while(q--){
		cin >> num;
		cout << upper_bound(a+1,a+n+1,num)-a-1 << '\n';
	}
	return 0;
}