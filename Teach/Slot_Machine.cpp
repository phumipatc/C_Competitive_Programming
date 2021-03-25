/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	:
	Status	:
*/
#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define allst(x,y) (x).begin()+y,(x).end()
#define decp(x) fixed << setprecision(x)
#define MOD (LL )(1e9+7)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
const int MAX_INT = 1e9;
const LL MAX_LL = 1e18;
LL minN(vector<LL > a){
	LL minn = 1e18;
	for(auto x:a)
		minn = min(minn,x);
	return minn;
}
LL maxN(vector<LL > a){
	LL maxx = -1e18;
	for(auto x:a)
		maxx = max(maxx,x);
	return maxx;
}
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 0;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
int a[20][10];
struct A{
	int i,j,k,l,m;
};
queue<A > que;
void solve(){
	int n,mn,mx;
	cin >> n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=5;j++)
			cin >> a[i][j];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				for(int l=1;l<=n;l++){
					for(int m=1;m<=n;m++){
						mn = minN({a[i][1],a[j][2],a[k][3],a[l][4],a[m][5]});
						mx = maxN({a[i][1],a[j][2],a[k][3],a[l][4],a[m][5]});
						if(mn == mx)
							que.push({i,j,k,l,m});
					}
				}
			}
		}
	}
	cout << que.size() << '\n';
	while(!que.empty()){
		A now = que.front();
		que.pop();
		cout << now.i << ' ' << now.j << ' ' << now.k << ' ' << now.l << ' ' << now.m << '\n';
	}
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q = 1;
	// cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}