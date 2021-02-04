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
	int q,n,a,b;
	cin >> q;
	while(q--){
		cin >> n >> a >> b;
		for(int i=0;i<n;i++)
			cout << char('a'+(i%b));
		cout << '\n';
	}
	return 0;
}