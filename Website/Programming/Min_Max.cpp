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
	int n,num,minn = 2e9,maxx = -2e9;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> num;
		minn = min(minn,num);
		maxx = max(maxx,num);
	}
	cout << minn << '\n' << maxx << '\n';
	return 0;
}