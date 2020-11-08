/*
    Author	: Phumipat C. [MAGCARI]
    School	: RYW
    Langauge: C++
    Algo	: Implementing
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int ,int > PII;
typedef pair<long long ,long long > PLL;
PLL a[110];
LL dist(PLL a,PLL b){
	return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	LL m,n,countt,x,y,r,ans = 0;
	cin >> m >> n;
	for(int i=1;i<=m;i++)
		cin >> a[i].first >> a[i].second;
	for(int i=1;i<=n;i++){
		cin >> x >> y >> r;
		countt = 0;
		for(int j=1;j<=m;j++)
			countt+=dist(a[j],{x,y})<(r*r);
		ans+=(countt>0 && countt<m);
	}
	cout << ans << '\n';
    return 0;
}