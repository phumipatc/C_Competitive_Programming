/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[3010],pos[3010],LIS[3010];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,maxx = 0,idx;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++){
		cin >> idx;
		pos[idx] = i;
	}
	for(int i=1;i<=n;i++){
		idx = upper_bound(LIS,LIS+maxx,pos[a[i]])-LIS;
		if(idx == maxx)	maxx++;
		LIS[idx] = pos[a[i]];
	}
	cout << maxx << '\n';
	return 0;
}