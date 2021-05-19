/*
	Task	: Travelling_Merchant
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 18 May 2021 [15:03]
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
const int N = 110;
const int mxK = 1010;
LL prof[N][N],dis[N][N],eff[N][N],buy[N][mxK],sell[N][mxK];
int n,m,K;
bool check(LL val){
	rep(i,1,n)	rep(j,1,n)	eff[i][j] = -1e18;
	rep(i,1,n){
		rep(j,1,n){
			if(dis[i][j] == 1e18)	continue;
			eff[i][j] = max(eff[i][j],prof[i][j] - val*dis[i][j]);
		}
	}
	rep(k,1,n){
		rep(i,1,n){
			rep(j,1,n){
				eff[i][j] = max(eff[i][j],eff[i][k] + eff[k][j]);
			}
		}
	}
	rep(i,1,n)
		if(eff[i][i]>=0)
			return true;
	return false;
}
void solve(){
	int u,v;
	LL w;
	cin >> n >> m >> K;
	rep(i,1,n)
		rep(j,1,K)
			cin >> buy[i][j] >> sell[i][j];
	rep(i,1,n)	rep(j,1,n)	dis[i][j] = 1e18;
	while(m--){
		cin >> u >> v >> w;
		dis[u][v] = min(dis[u][v],w);
	}
	rep(k,1,n){
		rep(i,1,n){
			rep(j,1,n){
				if(dis[i][k] == 1e18 || dis[k][j] == 1e18)	continue;
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
			}
		}
	}
	rep(l,1,K){
		rep(i,1,n){
			rep(j,1,n){
				if(dis[i][j] == 1e18 || buy[i][l] == -1 || sell[j][l] == -1)	continue;
				prof[i][j] = max(prof[i][j],sell[j][l] - buy[i][l]);
			}
		}
	}
	
	LL l = 0,r = 1e9,mid;
	while(l<r){
		mid = (l+r+1)/2;
		if(check(mid))	l = mid;
		else			r = mid-1;
	}
	cout << l << '\n';
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int q = 1;
	// cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}