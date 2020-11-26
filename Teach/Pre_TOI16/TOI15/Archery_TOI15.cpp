/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: 
	Status	: 
*/
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
PII a[500010];
LL qs[500010],qs2[500010];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,idx,minn = 1e9;
	LL ans = 1e18,sum;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i].second,minn = min(minn,a[i].second);
	for(int i=1;i<=n;i++)
		cin >> a[i].first;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		qs[i] = a[i].first+qs[i-1];
		qs2[i] = a[i].second+qs2[i-1];
	}
	for(int i=1;i<=n;i++){
		if(a[i].first>minn)	break;
		sum = (qs[n]-qs[i]) - (LL )(n-i)*a[i].first;
		sum+= qs[i-1] + qs2[i-1] - (LL )(i-1)*a[i].first;
		if(sum<ans){
			ans = sum;
			idx = a[i].first;
		}
	}
	cout << idx << ' ' << ans << '\n';
	return 0;
}