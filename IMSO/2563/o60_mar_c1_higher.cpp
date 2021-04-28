/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Square Decomposition
	Status	: Finished
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
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
int a[1000010],cluster[1010];
int now(int x){
	return (x/1000);
}
int next(int x){
	return (x/1000)+1;
}
void solve(){
	int n,k,h,x,l,r;
	cin >> n >> k;
	while(k--){
		cin >> x >> h;
		a[x] = h;
		cluster[now(x)] = 0;
		for(int i=now(x)*1000;i<next(x)*1000;i++)
			cluster[now(x)] = max(cluster[now(x)],a[i]);
		l = -1,r = n;
		for(int i=x;i>=now(x)*1000;i--){
			if(a[i]>h){
				l = i+1;
				break;
			}
		}
		for(int i=x;i<next(x)*1000;i++){
			if(a[i]>h){
				r = i-1;
				break;
			}
		}
		for(int i=now(x)-1;l == -1 && i>=0;i--){
			if(cluster[i]<=h)	continue;
			for(int j=((i+1)*1000)-1;j>=i*1000;j--){
				if(a[j]>h){
					l = j+1;
					break;
				}
			}
			break;
		}
		for(int i=next(x);r == n && i<=n/1000;i++){
			if(cluster[i]<=h)	continue;
			for(int j=i*1000;j<(i+1)*1000;j++){
				if(a[j]>h){
					r = j-1;
					break;
				}
			}
			break;
		}
		if(l == -1 && r == n)	cout << n << '\n';
		else if(l == -1)		cout << r-x << '\n';
		else if(r == n)			cout << x-l << '\n';
		else					cout << min(x-l,r-x) << '\n';
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