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
string str;
int maxlv,idx;
void find_lv(int lvl){
	maxlv = max(maxlv,lvl);
	if(str[idx]-'0'){
		for(int i=0;i<4;i++){
			idx++;
			find_lv(lvl+1);
		}
	}
}
char a[2050][2050];
void recurse(int sti,int stj,int n){
	if(n == 1){
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				if(i == 0 || j == 0 || i == 2 || j == 2)
					a[sti+i][stj+j] = '#';
		return ;
	}
	if(str[idx]-'0'){
		idx++;
		recurse(sti,stj,n-1);
		idx++;
		recurse(sti,stj+(1<<(n-1)),n-1);
		idx++;
		recurse(sti+(1<<(n-1)),stj,n-1);
		idx++;
		recurse(sti+(1<<(n-1)),stj+(1<<(n-1)),n-1);
	}else{
		for(int i=0;i<(1<<n)+1;i++)
			for(int j=0;j<(1<<n)+1;j++)
				if(i == 0 || j == 0 || i == (1<<n) || j == (1<<n))
					a[sti+i][stj+j] = '#';
	}
}
void solve(){
	cin >> str;
	idx = 0,maxlv = 0;
	find_lv(1);
	// cout << maxlv << '\n';
	memset(a,'-',sizeof a);
	idx = 0;
	recurse(1,1,maxlv);
	for(int i=1;i<=(1<<maxlv)+1;i++){
		for(int j=1;j<=(1<<maxlv)+1;j++)
			cout << a[i][j];
		cout << '\n';
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