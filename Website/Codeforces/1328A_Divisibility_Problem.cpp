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
	int q,a,b;
	cin >> q;
	while(q--){
		cin >> a >> b;
		cout << (int )(ceil((double )a/b)*b)-a << '\n';
	}
	return 0;
}