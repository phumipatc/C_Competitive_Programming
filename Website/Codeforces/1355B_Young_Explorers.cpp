/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int solve(vector<int > a){
	sort(a.begin(),a.end());
	int countt = 0,pos = 0;
	for(int i=0;i<a.size();i++){
		if(i-pos+1>=a[i]){
			countt++;
			pos = i+1;
		}
	}
	return countt;
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q,n;
	vector<int > a;
	cin >> q;
	while(q--){
		cin >> n;
		a.resize(n);
		for(int i=0;i<n;i++)
			cin >> a[i];
		cout << solve(a) << '\n';
	}
	return 0;
}