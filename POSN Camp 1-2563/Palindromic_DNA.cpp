/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Bruteforce
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
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
string str;
char mark[30];
vector<pair<int ,string > > ans;
int check(int l,int r){
	while(l<=r){
		if(mark[str[l]-'A']!=str[r])	return 0;
		l++,r--;
	}
	return 1;
}
void solve(){
	mark['A'-'A'] = 'T',mark['T'-'A'] = 'A';
	mark['C'-'A'] = 'G',mark['G'-'A'] = 'C';
	cin >> str;
	ans.clear();
	int maxx = 0;
	for(int i=0;i<str.length();i++){
		for(int j=str.length()-1;j>=i;j--){
			if(!check(i,j))	continue;
			if(j-i+1>maxx){
				maxx = j-i+1;
				ans.clear();
			}
			if(j-i+1 == maxx)	ans.push_back({i+1,str.substr(i,maxx)});
		}
	}
	if(ans.empty()){
		cout << "No palindromic sequence found\n";
		return ;
	}
	cout << maxx << '\n' << ans.size() << '\n';
	for(auto x:ans){
		cout << x.first << '\n' << x.second << '\n';
		for(auto y:x.second)
			cout << mark[y-'A'];
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