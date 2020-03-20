/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int > g[100010];
pair<int ,int > p[300010];
int col[100010];
int dfs(int now,int c){
	if(col[now]){
		if(col[now] == c)	return 1;
		else				return 0;
	}
	col[now] = c;
	for(auto x:g[now]){
		if(!dfs(x,3-c))
			return 0;
	}
	return 1;
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=m;i++)
		cin >> p[i].first >> p[i].second;
	int l = 1,r = m;
	while(l<r){
		int mid = (l+r+1)/2,ch = 1;
		for(int i=1;i<=mid;i++){
			g[p[i].first].push_back(p[i].second);
			g[p[i].second].push_back(p[i].first);
		}
		for(int i=1;i<=n;i++){
			if(col[i])	continue;
			ch = min(ch,dfs(i,1));
		}
		// printf("%d %d\n",mid,ch);
		for(int i=1;i<=n;i++)
			g[i].clear();
		memset(col,0,sizeof col);
		if(ch)	l = mid;
		else	r = mid-1;
	}
	cout << l+1 << '\n';
	return 0;
}
/*
6 8
3 4
1 2
5 6
1 6
1 3
4 5
2 4
2 6
*/