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
	int q,n;
	cin >> q;
	while(q--){
		cin >> n;
		cout << (n-1)/2 << '\n';
	}
	return 0;
}