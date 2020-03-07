/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[100010],b[100010];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++)
		cin >> b[i];
	cin >> m;
	int l = 0,r = 1e9;
	while(l<r){
		LL mid = (l+r+1)/2,need = 0;
		for(int i=1;i<=n;i++)
			need+=max(0ll,(a[i]*mid)-b[i]);
		if(need<=m)	l = mid;
		else		r = mid-1;
	}
	cout << l << '\n';
	return 0;
}