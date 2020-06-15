/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[1010][1010];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,m,t,x,y;
	cin >> n >> m >> t;
	for(int i=1;i<=n;i++){
		cin >> x >> y;
		a[x+1][y+1]++;
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
	int l,r,mid,ans = 1e9;
	for(int i=1;i<=m;i++){
		for(int j=i;j<=m;j++){
			l = 1,r = m;
			while(l<r){
				mid = (l+r)/2;
				if(a[mid][j]-a[mid][i-1]>=t)	r = mid;
				else							l = mid+1;
			}
			if(a[l][j]-a[l][i-1]>=t)
				ans = min(ans,(j-i+1)*l);
		}
	}
	cout << ans << '\n';
	return 0;
}