/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct A{
	int u,v;
	bool operator < (const A&o) const{
		return v<o.v;
	}
};
A a[100010],b[100010];
int l[100010][2],r[100010][2],s[100010];
//0 minus	1 plus
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i].v >> a[i].u;
	for(int i=1;i<=n;i++)
		cin >> b[i].v >> b[i].u;
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		s[i] = b[i].v;
		l[i][0] = r[i][0] = b[i].u-b[i].v;
		l[i][1] = r[i][1] = b[i].u+b[i].v;
	}
	for(int i=2;i<=n;i++){
		l[i][0] = max(l[i][0],l[i-1][0]);
		l[i][1] = max(l[i][1],l[i-1][1]);
	}
	for(int i=n-1;i>=1;i--){
		r[i][0] = max(r[i][0],r[i+1][0]);
		r[i][1] = max(r[i][1],r[i+1][0]);
	}
	for(int i=1;i<=n;i++){
		int idx = upper_bound(s+1,s+n+1,a[i].v)-s;
		int ans = -1e9;
		if(idx<=n)	ans = max(ans,a[i].u+a[i].v+r[idx][0]);
		if(idx-1>0)	ans = max(ans,a[i].u-a[i].v+l[idx-1][1]);
		cout << ans << '\n';
	}
	return 0;
}