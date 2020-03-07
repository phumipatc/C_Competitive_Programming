/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int > g[200010];
int dp[200010][18];
int last;
void dfs(int now){
	if(g[now].size() == 0)	return ;
	for(auto x:g[now])
		dfs(x);
	if(g[now].size() == 1){
		dp[now][0] = g[now][0];
		for(int i=1;i<=17;i++){
			if(dp[now][i-1] == -1)	break;
			dp[now][i] = dp[dp[now][i-1]][i-1];
		}
	}
}
int s,a,b;
int dir() {
	int res = ((s & 8) >> 3);
	s = (s * a + b) % 40507;
	return res;
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,q,l,r;
	cin >> n >> q;
	for(int i=0;i<n;i++){
		cin >> l >> r;
		if(l!=-1)	g[i].push_back(l);
		if(r!=-1)	g[i].push_back(r);
	}
	memset(dp,-1,sizeof dp);
	dfs(0);
	while(q--){
		cin >> l >> s >> a >> b;
		int now = 0;
		// cout << "###\n";
		while(l>0){
			// cout << now << ' ' << l << '\n';
			if(g[now].size() == 0){
				cout << now << '\n';
				break;
			}else if(g[now].size() == 1){
				for(int i=17;i>=0;i--){
					if(dp[now][i] == -1)	continue;
					if((1<<i) > l)			continue;
					// cout << "Next: " << i << ' ' << dp[now][i] << '\n';
					now = dp[now][i];
					l-=(1<<i);
					break;
				}
			}else{
				int res = dir();
				l--;
				now = g[now][res];
			}
		}
		if(l == 0)
			cout << now << '\n';
	}
	return 0;
}