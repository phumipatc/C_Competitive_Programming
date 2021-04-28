/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Image Printing
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
vector<char > c;
void solve(){
	int n,last;
	cin >> n;
	for(int i=0;i<26;i++)
		c.push_back('A'+i);
	for(int i=0;i<10;i++)
		c.push_back('0'+i);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++)
			cout << '.';
		cout << c[(i-1)%c.size()];
		for(int j=1;j<=(i-1)*2-1;j++)
			cout << '*';
		if(i!=1)	cout << c[(n+(n-1)+(n-1)+n-i-1)%c.size()];
		for(int j=i+1;j<=n;j++)
			cout << '.';
		cout << '\n';
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=i;j++)
			cout << '.';
		cout << c[(n+i-1)%c.size()];
		for(int j=1;j<=(n-i-1)*2-1;j++)
			cout << '*';
		if(i!=n-1)	cout << c[(n+(n-1)+(n-1)-i-1)%c.size()];
		for(int j=1;j<=i;j++)
			cout << '.';
		cout << '\n';
	}
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