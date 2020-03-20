/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[2000010];
vector<int > v;
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	LL l = 0,r = 3e9;
	while(l<r){
		LL mid = (l+r)/2;
		v.clear();
		for(int i=1;i<=n;i++){
			if(a[i]<=mid)	continue;
			v.push_back(a[i]);
		}
		int can = 1;
		for(int i=0;i<v.size();i+=2){
			if(v[i]!=v[i+1]){
				can = 0;
				break;
			}
		}
		if(can)	r = mid;
		else	l = mid+1;
	}
	cout << l << '\n'; 
	return 0;
}