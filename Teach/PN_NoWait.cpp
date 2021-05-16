/*
	Task	: PN_NoWait
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 13 May 2021 [19:48]
	Algo	: 
	Status	: Untest
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x),end(x)
#define allst(x,y) (x).begin()+y,(x).end()
#define rmdup(x) (x).resize(unique((x).begin(),(x).end())-(x).begin())
#define sz(x) (int)(x).size()
#define decp(x) fixed << setprecision(x)
#define MOD (LL )(1e9+7)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2,c);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
const int N = 500010;
int nx[N],val[N],in[N];
vector<int > rv[N],groups;
int mark[N];
int dfs(int now){
	if(rv[now].empty())	return val[now];
	vector<int > ret;
	for(auto x:rv[now])
		ret.push_back(dfs(x));
	sort(all(ret));
	rep(i,0,sz(ret)-1)	groups.push_back(ret[i]);
	return val[now] + ret.back();
}
void solve(){
	int n,K;
	queue<int > que;
	cin >> n;
	rep(i,1,n+1){
		cin >> nx[i] >> val[i];
		in[nx[i]]++;
		rv[nx[i]].push_back(i);
	}
	cin >> K;
	rep(i,1,n+1){
		if(in[i])	continue;
		que.push(i);
	}
	while(!que.empty()){
		int now = que.front();
		que.pop();
		in[nx[now]]--;
		if(in[nx[now]])	continue;
		que.push(nx[now]);
	}
	rep(i,1,n+1){
		if(mark[i])	continue;
		if(!in[i])	continue;
		int sum = val[i];
		mark[i] = 1;
		vector<int > temp;
		for(auto x:rv[i]){
			if(in[x])	continue;
			temp.push_back(dfs(x));
		}
		for(int j=nx[i];j!=i;j=nx[j]){
			sum+=val[j];
			mark[j] = 1;
			for(auto x:rv[j]){
				if(in[x])	continue;
				temp.push_back(dfs(x));
			}
		}
		if(!temp.empty()){
			sort(all(temp));
			sum+=temp.back();
			groups.push_back(sum);
			temp.pop_back();
			for(auto x:temp)
				groups.push_back(x);
		}
		temp.clear();
	}
	sort(all(groups));	reverse(all(groups));
	int ans = 0;
	for(int i=0;i<=K && i<=sz(groups);i++)
		ans+=groups[i];
	cout << ans << '\n';
	rep(i,1,n+1)	rv[i].clear();
	fill(in,in+n+1,0);
	fill(mark,mark+n+1,0);
	groups.clear();
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int q = 1;
	cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}