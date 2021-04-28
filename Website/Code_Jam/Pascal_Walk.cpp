/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	:
	Status	: Unfinished
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
int a[100][100];
void solve(){
	int n,sum = 0;
	PII now = {1,1};
	cin >> n;
	n-=30;
	for(int i=0;i<=30 && sum<=n+30;i++){
		if(!((1<<i)&n)){
			sum++;
			cout << i << ' ' << now.second << '\n';
			if(now.second != 1)	now.second++;
			continue;
		}
		sum += (1<<i);
		if(now.second == 1){
			for(int j=1;j<=i;j++)
				cout << i << ' ' << j << '\n';
			now.second = i + 1;
		}else{

		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	for(int i=1;i<=100;i++){
		a[i][1] = a[i][i] = 1;
		for(int j=2;j<i;j++){
			a[i][j] = a[i-1][j-1] + a[i-1][j];
		}
	}
	int q = 1;
	cin >> q;
	for(int Q=1;Q<=q;Q++){
		cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}