/*
	Task	: Peatt_Pacman
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Created	: 10 May 2021 [09:50]
	Algo	: BFS
	Status	: Finished
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x),end(x)
#define allst(x,y) (x).begin()+y,(x).end()
#define remdup(x) (x).resize(unique((x).begin(),(x).end())-(x).begin())
#define sz(x) (int)(x).size()
#define decp(x) fixed << setprecision(x)
#define MOD (LL )(1e9+7)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
const int MAX_INT = 2e9;
const LL MAX_LL = 1e18;
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2,c);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
const int N = 710;
struct A{
	int i,j,id;
};
queue<A > que[2];
vector<PII > spawn[490010];
int mark[N][N];	//1 -> pacman 2 -> ghost
char a[N][N];
void solve(){
	memset(mark,0,sizeof mark);
	rep(i,0,2)
		while(!que[i].empty())	que[i].pop();
	for(int i=0;i<=490000;i++)	spawn[i].clear();
	int r,c,n,T,sti,stj,cnt = 1;
	cin >> r >> c >> n >> T >> sti >> stj;
	while(n--){
		int i,j,k;
		cin >> k >> i >> j;
		if(k == 0)	mark[i][j] = 2,que[1].push({i,j,2});
		else		spawn[k].push_back({i,j});
	}
	rep(i,0,r)
		cin >> a[i];
	if(mark[sti][stj]){
		cout << "NO -1\n";
		return ;
	}
	que[1].push({sti,stj,1});
	mark[sti][stj] = 1;
	int t;
	for(t=1;t<=T;t++){
		int current = t&1,nx = current^1;
		for(auto x:spawn[t]){
			que[nx].push({x.first,x.second,2});
			if(mark[x.first][x.second] == 1)	cnt--;
			mark[x.first][x.second] = 2;
		}
		while(!que[current].empty()){
			A now = que[current].front();
			que[current].pop();
			for(int k=0;k<4;k++){
				int ni = now.i + dir4[0][k],nj = now.j + dir4[1][k];
				if(ni<0 || nj<0 || ni>=r || nj>=c)	continue;
				if(a[ni][nj] == '#')				continue;
				if(now.id == 1 && mark[ni][nj])		continue;
				if(now.id == 2){
					if(mark[ni][nj] == 1)			cnt--;
					if(mark[ni][nj] == 2)			continue;
				}
				mark[ni][nj] = now.id;
				cnt+=(now.id == 1);
				que[nx].push({ni,nj,now.id});
			}
		}
		if(cnt == 0)	break;
	}
	if(cnt)	cout << "YES\n";
	else	cout << "NO " << t-1 << '\n';
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