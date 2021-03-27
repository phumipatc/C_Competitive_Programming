/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	:
	Status	: Unfinished [Sol for Test Set 1 only]
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
int a[110],b[110];
int cal(int n){
	int idx,ans = 0;
	for(int i=1;i<n;i++){
		for(int j=i,minn = 1e9;j<=n;j++){
			if(minn<=a[j])	continue;
			idx = j;
			minn = a[j];
		}
		ans+=idx-i+1;
		for(int j=i;j<=(idx+i)/2;j++)
			swap(a[j],a[idx-j+i]);
	}
	return ans;
}
void solve(){
	int n,c;
	cin >> n >> c;
	if(n>7)	return ;
	for(int i=1;i<=n;i++)
		a[i] = i;
	do{
		for(int i=1;i<=n;i++)
			b[i] = a[i];
		if(cal(n) == c){
			for(int i=1;i<=n;i++)
				cout << b[i] << ' ';
			cout << '\n';
			return ;
		}
		for(int i=1;i<=n;i++)
			a[i] = b[i];
	}while(next_permutation(a+1,a+n+1));
	cout << "IMPOSSIBLE\n";
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q = 1;
	cin >> q;
	for(int Q=1;Q<=q;Q++){
		cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}