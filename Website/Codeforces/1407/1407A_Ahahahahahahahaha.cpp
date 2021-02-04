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
int a[1010],countt[2];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q,n;
	cin >> q;
	while(q--){
		cin >> n;
		countt[0] = countt[1] = 0;
		for(int i=1;i<=n;i++){
			cin >> a[i];
			countt[a[i]]++;
		}
		int target = countt[0]<countt[1]?0:1;
		if(countt[0] == countt[1])	n/=2,target = 1;
		else						n = (countt[!target]/2)*2;
		cout << n << '\n';
		for(int i=1;i<=n;i++)
			cout << !target << ' ';
		cout << '\n';
	}
	return 0;
}