/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
void solve(int n){
	for(int i=0;i<n;i++){
		for(int j=1;j<=2*(n-i)-1;j++)
			cout << ' ';
		for(int j=0;j<=i;j++)
			cout << ' ' << j;
		for(int j=i-1;j>=0;j--)
			cout << ' ' << j;
		cout << '\n';
	}
	cout << '0';
	for(int j=1;j<=n;j++)
		cout << ' ' << j;
	for(int j=n-1;j>=0;j--)
		cout << ' ' << j;
	cout << '\n';
	for(int i=n-1;i>=0;i--){
		for(int j=1;j<=2*(n-i)-1;j++)
			cout << ' ';
		for(int j=0;j<=i;j++)
			cout << ' ' << j;
		for(int j=i-1;j>=0;j--)
			cout << ' ' << j;
		cout << '\n';
	}
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	solve(n);
	return 0;
}