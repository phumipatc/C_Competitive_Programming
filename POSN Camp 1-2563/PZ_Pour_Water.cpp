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
int mark[210][210][210],dp[210];
int A,B,C,D;
void recurse(int a,int b,int c,int sum){
	if(a<0 || b<0 || c<0 || a>A || b>B || c>C)	return ;
	if(mark[a][b][c]!=-1 && mark[a][b][c]<=sum)	return ;
	dp[a] = min(dp[a],sum);
	dp[b] = min(dp[b],sum);
	dp[c] = min(dp[c],sum);

	mark[a][b][c] = sum;
	//Pour A to others
	recurse(0,a+b,c,sum+a);			recurse(0,b,a+c,sum+a);
	recurse(a-(B-b),B,c,sum+(B-b));	recurse(a-(C-c),b,C,sum+(C-c));

	//Pour B to others
	recurse(a+b,0,c,sum+b);			recurse(a,0,b+c,sum+b);
	recurse(A,b-(A-a),c,sum+(A-a));	recurse(a,b-(C-c),C,sum+(C-c));

	//Pour C to others
	recurse(a+c,b,0,sum+c);			recurse(a,b+c,0,sum+c);
	recurse(A,b,c-(A-a),sum+(A-a));	recurse(a,B,c-(B-b),sum+(B-b));
}
void solve(){
	cin >> A >> B >> C >> D;
	memset(mark,-1,sizeof mark);
	dp[0] = 0;
	for(int i=1;i<=200;i++)
		dp[i] = 1e9;
	recurse(0,0,C,0);
	if(dp[D]!=1e9)	cout << dp[D] << ' ' << D << '\n';
	else{
		for(int i=D-1;i>=0;i--){
			if(dp[i] == 1e9)	continue;
			cout << dp[i] << ' ' << i << '\n';
			return ;
		}
	}
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