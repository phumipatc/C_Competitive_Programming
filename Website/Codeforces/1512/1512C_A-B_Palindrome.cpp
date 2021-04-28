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
void solve(){
	int a,b;
	string str;
	cin >> a >> b >> str;
	int n = str.length(),l,r;
	for(int i=0;i<n;i++)
		a-=(str[i] == '0'),b-=(str[i] == '1');
	for(l = 0,r = n-1;l<=r;l++,r--){
		if(str[l] == str[r])	continue;
		if(str[l] == '?'){
			str[l] = str[r];
		}else if(str[r] == '?'){
			str[r] = str[l];
		}else{
			a = -1;
			break;
		}
		if(str[l] == '0')	a--;
		else				b--;
	}
	for(l = 0,r = n-1;l<=r;l++,r--){
		if(str[l] == str[r] && str[l]!='?')	continue;
		if(a>=b)	str[l] = str[r] = '0',a-=(l == r)?1:2;
		else		str[l] = str[r] = '1',b-=(l == r)?1:2;
	}
	if(min(a,b) == max(a,b) && min(a,b) == 0)	cout << str << '\n';
	else										cout << "-1\n";
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