/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Compound Numbers
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
	if(b == 0)	return 0;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
vector<int > comp[1000010];
int cnt(int n){
	if(n == 1)		return 0;
	int ret = 1e9;
	for(auto x:comp[n])
		ret = min(ret,cnt(x) + 3 + (n/x) - 1);
	return ret;
}
vector<char > ans;
void solve(int n){
	// printf("now:%d\n",n);
	if(n == 1)	return ;
	int minn = 1e9,idx;
	for(auto x:comp[n]){
		// printf("comp:%d %d\n",x,cnt(x) + (n/x) - 1);
		if(cnt(x) + (n/x) - 1<minn){
			minn = cnt(x) + (n/x) - 1;
			idx = x;
		}
	}
	solve(idx);
	ans.push_back('A'),ans.push_back('C'),ans.push_back('V');
	for(int i=1;i<(n/idx);i++)
		ans.push_back('V');
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	freopen("o64_feb_c2_kon.out","w",stdout);
	int q = 10;
	int Q[] = {0,9,30,1219,50220,124609,508394,649424,882660,945595,1000000};

	for(int i=1;i<=sqrt(1000000);i++)
		for(int j=2;i*j<=1000000;j++)
			comp[i*j].push_back(i);

	cout << q << '\n';
	for(int i=1;i<=q;i++){
		cout << i << '\n';
		ans.clear();
		solve(Q[i]);
		for(auto x:ans)
			cout << x;
		cout << '\n';
	}
	return 0;
}