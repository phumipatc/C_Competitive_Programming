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
#define nl now*2
#define nr now*2+1
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
list<string > listt;
list<string >::iterator it,it2;
//insert = before that element
//erase = that element & must create it2 pointing at the element
void solve(){
	int n;
	cin >> n;
	listt.push_back("-");
	it = listt.begin();

	char opr;
	string str;
	while(n--){
		cin >> opr;
		if(opr == 'l' and it!=listt.begin())	it--;
		else if(opr == 'r' and *it!="-")		it++;
		else if(opr == 'i'){
			cin >> str;
			listt.insert(it,str);
		}else if(opr == 'b' and it!=listt.begin()){
			it2 = it,it2--;
			listt.erase(it2);
		}else if(opr == 'd' && *it!="-"){
			it2 = it,it++;
			listt.erase(it2);
		}
	}
	listt.pop_back();
	for(auto x:listt)
		cout << x << ' ';
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q = 1;
	// cin >> q;
	while(q--){
		solve();
	}
	return 0;
}