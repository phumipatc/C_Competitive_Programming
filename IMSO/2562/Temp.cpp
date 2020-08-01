/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define INF 1e18
#define pb(a) push_back(a)
using namespace std;
typedef long long LL;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{1,0,-1,1,1,0,-1,-1}};
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	vector<int> v;
	int n;
	cin >> n;
	cout << n;
	v.push_back(10);
	for(auto x:v){
		cout << x;
	}
	return 0;
}