/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	:
	Status	:
*/
#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define allst(x,y) (x).begin()+y,(x).end()
#define sz(x) (int)(x).size()
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
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
vector<int > pos[30];
vector<char > cat[30];
int mark[100010];
void solve(){
	for(int i=0;i<26;i++)
		pos[i].clear(),cat[i].clear();
	memset(mark,0,sizeof mark);
	string str,ans;
	cin >> str;
	int idx,maxx = -1;
	for(int i=0;i<sz(str);i++){
		char x = str[i];
		pos[x-'a'].push_back(i);
	}
	for(int i=0;i<26;i++){
		if(pos[i].empty())	continue;
		int ch = 0;
		for(auto x:pos[i]){
			if(x>maxx){
				maxx = x;
				ch = 1;
				mark[x] = 1;
				break;
			}
		}
		if(!ch)	mark[pos[i][sz(pos[i])-1]] = 1;
	}
	for(int i=0;i<sz(str);i++){
		if(!mark[i])	continue;
		ans.push_back(str[i]);
	}
	string temp;
	for(int i=0;i<26;i++){
		if(!pos[i].empty())	continue;
		temp.push_back('a'+i);
	}
	int l = 0,r = 0;
	while(l<sz(ans) && r<sz(temp)){
		if(ans[l]<temp[r])	cout << ans[l++];
		else				cout << temp[r++];
	}
	while(l<sz(ans))	cout << ans[l++];
	while(r<sz(temp))	cout << temp[r++];
	cout << '\n';
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int q = 1;
	cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}