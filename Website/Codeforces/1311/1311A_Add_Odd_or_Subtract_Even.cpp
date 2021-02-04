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
		if(a == b){
			cout << "0\n";
			continue;
		}
		if(a<b){
			if((a%2) == !(b%2))	cout << "1\n";
			else				cout << min(2,b-a) << '\n';
		}else{
			if((a%2) == (b%2))	cout << "1\n";
			else				cout << "2\n";
		}
	}
	return 0;
}