/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: LCA
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
struct A{
	int num,l,r;
};
A tree[200010];
int n;
int LCA[200010][20];
void dfs(int u){
	if(!tree[u].num)		return ;
	if(tree[u].l)			dfs(tree[u].l);
	if(tree[u].r)			dfs(tree[u].r);
	if(tree[u].num == 2)	return ;
	LCA[u][0] = tree[u].l;
	for(int i=1;i<=18;i++)
		LCA[u][i] = LCA[LCA[u][i-1]][i-1];
}
void initial(){
	int l,r;
	for(int i=0;i<n;i++){
		cin >> l >> r;
		if(l!=-1)	tree[i].num++,tree[i].l = l;
		if(r!=-1)	tree[i].num++,tree[i].r = r;
		if(tree[i].l == 0)	swap(tree[i].l,tree[i].r);
	}
	dfs(0);
}
int s,a,b;
int dir(){
	int res = ((s&8) >> 3);
	s = (s * a + b)%40507;
	return res;
}
void solve(){
	int l,now = 0;
	cin >> l >> s >> a >> b;
	while(l>0){
		if(tree[now].num == 0)	break;
		if(tree[now].num == 2){
			l--;
			if(dir() == 0)	now = tree[now].l;
			else			now = tree[now].r;
			continue;
		}
		for(int i=18;i>=0;i--){
			if((1<<i)>l)			continue;
			if(LCA[now][i] == 0)	continue;
			l-=(1<<i);
			now = LCA[now][i];
			break;
		}
	}
	cout << now << '\n';
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q = 1;
	cin >> n >> q;
	initial();
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}