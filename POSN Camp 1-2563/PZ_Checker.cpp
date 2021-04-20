/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Recursive
	Status	: Untest
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
char a[32][32];
const int dir[2][4] = {{-1,-1,1,1},{-1,1,-1,1}};
int cnt;
vector<PII > ans;
int n;
int recurse(int i,int j){
	if(cnt == 0){
		for(auto x:ans)
			cout << x.first << ' ' << x.second << '\n';
		return 1;
	}
	for(int k=0;k<4;k++){
		int ni = i+dir[0][k],nj = j+dir[1][k];
		int nii = ni+dir[0][k],njj = nj+dir[1][k];
		if(nii<1 || njj<1 || nii>n || njj>n)	continue;
		if(a[ni][nj] != 'o')					continue;
		if(a[nii][njj] != '+')					continue;
		a[ni][nj] = '+';
		cnt--;
		ans.push_back({nii,njj});
		if(recurse(nii,njj))	return 1;
		ans.pop_back();
		cnt++;
		a[ni][nj] = 'o';
	}
	return 0;
}
void solve(){
	cin >> n;
	cnt = 0;
	for(int i=1;i<=n;i++){
		cin >> a[i]+1;
		for(int j=1;j<=n;j++)
			cnt+=(a[i][j] == 'o');
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]!='K')	continue;
			ans.clear();
			ans.push_back({i,j});
			if(recurse(i,j) == 1)	return ;
		}
	}
	cout << "impossible\n";
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q = 1;
	cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}
/*
2
8
-+-+-+-+
+-+-+-+-
-+-K-+-+
+-+-+-+-
-o-o-+-+
+-K-+-+-
-o-+-+-+
+-K-+-K-
6
-o-K-+
+-+-+-
-+-o-+
+-K-+-
-+-o-+
+-K-+-
*/