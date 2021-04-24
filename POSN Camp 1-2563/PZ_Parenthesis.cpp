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
	if(b == 0)	return 0;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
vector<int > v;
stack<int > st;
void solve(){
	int x,y,z,cnt = 0;
	cin >> x >> y >> z;
	v.clear();
	while(x--)	v.push_back(1),v.push_back(-1);
	while(y--)	v.push_back(2),v.push_back(-2);
	while(z--)	v.push_back(3),v.push_back(-3);
	do
	{
		while(!st.empty())	st.pop();
		cnt++;
		for(auto x:v){
			if(x>0)	st.push(x);
			else{
				if(!st.empty() && st.top() == -x)	st.pop();
				else{
					cnt--;
					break;
				}
			}
		}
	} while (next_permutation(all(v)));
	cout << cnt << '\n';
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