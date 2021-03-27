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
int x,y;
int check(string a,string b){
	int sum = 0;
	// cout << a << ' ' << b << '\n';
	if(a == "CJ")		sum+=x;
	else if(a == "JC")	sum+=y;
	if(b == "CJ")		sum+=x;
	else if(b == "JC")	sum+=y;
	return sum;
}
void solve(){
	int minn = 0;
	string a,l,r,ll,rr,J = "J",C = "C";
	cin >> x >> y >> a;
	int len = a.length();
	a.push_back('0');
	reverse(all(a));
	a.push_back('0');
	reverse(all(a));
	for(int i=1;i<=len;i++){
		if(a[i]!='?'){
			minn+=check(a.substr(i-1,2),"00");
			continue;
		}
		// cout << a[i-1]+J << '\n';
		if(a[i] == '?' && a[i+1]!='?'){
			minn+=min(check(a[i-1]+J,J+a[i+1]),check(a[i-1]+C,C+a[i+1]));
			// printf("%d\n",minn);
			continue;
		}
		l = a[i-1];
		while(i<=len && a[i+1] == '?')	i++;
		r = a[i+1];
		minn+=minN({check(l+J,J+r),check(l+J,C+r)+y,check(l+C,J+r)+x,check(l+C,C+r)});
		// printf("%d\n",minn);
	}
	cout << minn << '\n';
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