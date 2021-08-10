/*
	Task	: 1551C_Interesting_Story
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 25 July 2021 [20:53]
	Algo	: 
	Status	: 
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i <= (b); ++i)
#define repr(i, a, b) for(int i = a; i >= (b); --i)
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
int cnt[5],sum[5];
void solve(){
	vector<int > v[5];
	int n;
	string str;
	cin >> n;
	rep(i,1,n){
		cin >> str;
		int all = 0;
		for(auto x:str)
			cnt[x-'a']++,all++;
		rep(i,0,4){
			sum[i]+=cnt[i]-(all-cnt[i]);
			v[i].emplace_back(-cnt[i]+(all-cnt[i]));
		}
		memset(cnt,0,sizeof cnt);
	}
	int mx = 0;
	rep(i,0,4){
		sort(all(v[i]));
		while(!v[i].empty()){
			// printf("%d %d\n",i,sum[i]);
			if(sum[i]>0)	mx = max(mx,sz(v[i]));
			sum[i]+=v[i].back();
			v[i].pop_back();
		}
	}
	cout << mx << '\n';
	memset(sum,0,sizeof sum);
	memset(cnt,0,sizeof cnt);
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