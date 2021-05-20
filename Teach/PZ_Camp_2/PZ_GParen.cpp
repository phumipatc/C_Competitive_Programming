/*
	Task	: PZ_GParen
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 19 May 2021 [13:52]
	Algo	: DP
	Status	: Finished
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i <= (b); ++i)
#define repr(i, a, b) for(int i = a; i >= (b); --i)
#define all(x) begin(x),end(x)
#define allst(x,y) (x).begin()+y,(x).end()
#define rmdup(x) (x).resize(unique((x).begin(),(x).end())-(x).begin())
#define sz(x) (int)(x).size()
#define decp(x) fixed << setprecision(x)
#define MOD (LL )(1e9+7)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2,c);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
const int N = 310;
LL dp[N][N],choose[N][N];
char a[N];
LL divide(int l,int r){
	if(dp[l][r]!=-1)	return dp[l][r];
	int num = 0;
	stack<char > st;
	vector<int > pos;
	rep(i,l,r){
		if(a[i] == '('){
			if(st.empty())	pos.push_back(i);
			st.push('(');
		}else{
			if(st.empty()){
				num = -1;
				break;
			}
			st.pop();
		}
	}
	if(num == -1 || !st.empty())	return dp[l][r] = 0;
	if(l+1 == r)					return dp[l][r] = 1;
	pos.push_back(r+1);
	LL sum = 0,ret = 1;
	vector<int > g;
	rep(i,0,sz(pos)-2){
		ret*=divide(pos[i]+1,pos[i+1]-2),ret%=MOD;
		g.push_back((pos[i+1]-pos[i])/2);
		sum+=(pos[i+1]-pos[i])/2;
	}
	for(auto x:g){
		ret*=choose[sum][x],ret%=MOD,sum-=x;
	}
	return dp[l][r] = ret;
}
void solve(){
	int n;
	cin >> n >> a+1;
	memset(dp,-1,sizeof dp);
	cout << divide(1,n) << '\n';
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	rep(i,0,300){
		rep(j,0,i){
			if(j == 0 || j == i)	choose[i][j] = 1;
			else					choose[i][j] = choose[i-1][j-1]+choose[i-1][j],choose[i][j]%=MOD;
		}
	}
	int q = 1;
	cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}