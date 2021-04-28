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
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
int a[22][22];
vector<int > b[22],temp;
void solve(){
	int n;
	string str;
	cin >> n >> str;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin >> a[i][j];
	if(str == "left" || str == "right"){
		for(int i=1;i<=n;i++){
			temp.clear();
			for(int j=1;j<=n;j++){
				if(!a[i][j])	continue;
				temp.push_back(a[i][j]);
			}
			if(str == "left")	reverse(all(temp));
			while(!temp.empty()){
				int u = temp.back();
				temp.pop_back();
				b[i].push_back(u);
				if(temp.empty())		break;
				if(temp.back() == u)	b[i].back()+=u,temp.pop_back();
			}
			while(b[i].size()<n)	b[i].push_back(0);
			if(str == "right")	reverse(all(b[i]));
		}
	}else{
		for(int j=1;j<=n;j++){
			temp.clear();
			for(int i=1;i<=n;i++){
				if(!a[i][j])	continue;
				temp.push_back(a[i][j]);
			}
			if(str == "up")	reverse(all(temp));
			int i=1;
			while(!temp.empty()){
				int u = temp.back();
				temp.pop_back();
				b[i++].push_back(u);
				if(temp.empty())		break;
				if(temp.back() == u)	b[i-1].back()+=u,temp.pop_back();
			}
			while(i<=n)	b[i++].push_back(0);
			if(str == "down")	reverse(all(b[i]));
		}
	}
	for(int i=1;i<=n;i++){
		for(auto x:b[i])
			cout << x << ' ';
		cout << '\n';
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