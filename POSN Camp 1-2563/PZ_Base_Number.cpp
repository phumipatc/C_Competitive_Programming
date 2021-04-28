/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Math [Base number]
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
LL p(int x,int n){
	LL ret = 1;
	for(int i=1;i<=n;i++)
		ret*=x;
	return ret;
}
void solve(){
	int a,b,sum = 0,n;
	string str;
	cin >> a >> b >> str;
	n = str.length()-1;
	for(auto x:str){
		if(isdigit(x))	sum+=(x-'0')*p(a,n);
		else			sum+=(x-'A'+10)*p(a,n);
		n--;
	}
	// cout << sum << '\n';

	vector<char > ans;
	n = 0;
	while(p(b,n)<=sum)	n++;
	while(n--){
		int now = p(b,n);
		ans.push_back((sum/now)<10?(sum/now)+'0':(sum/now)-10+'A'),sum%=now;
	}
	reverse(all(ans));
	while(!ans.empty() && ans.back() == '0')	ans.pop_back();
	reverse(all(ans));

	for(auto x:ans)
		cout << x;
	cout << '\n';
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