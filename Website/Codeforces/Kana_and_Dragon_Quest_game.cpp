/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q,x,n,m;
	cin >> q;
	while(q--){
		cin >> x >> n >> m;
		while(n-- && (x/2)+10<x)
			x = (x/2)+10;
		x-=10*m;
		if(x<=0)	cout << "YES\n";
		else		cout << "NO\n";
	}
	return 0;
}