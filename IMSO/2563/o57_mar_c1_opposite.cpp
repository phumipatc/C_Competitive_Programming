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
int dirr4[2][4] = {{-1,1,0,0},{0,0,-1,1}};
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
	int ai,aj,bi,bj,w;
};
queue<A > que;
A now;
char a[32][32];
int dist[32][32][32][32],dp[32][32][32][32];
int n,m;
void get_all_dist(){
	int ni,nj;
	memset(dist,-1,sizeof dist);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j] == '#')	continue;
			dist[i][j][i][j] = 0;
			que.push({i,j,0,0,0});
			while(!que.empty()){
				now = que.front();
				que.pop();
				for(int k=0;k<4;k++){
					ni = now.ai + dir4[0][k],nj = now.aj = dir4[1][k];
					if(ni<1 || nj<1 || ni>n || nj>m)	continue;
					if(a[ni][nj] == '#')				continue;
					if(dist[i][j][ni][nj]!=-1)			continue;
					dist[i][j][ni][nj] = now.w+1;
					que.push({ni,nj,0,0,now.w+1});
				}
			}
		}
	}
}
void minuss(){
	string sa,sb;
	vector<int > a,b;
	int mark;
	cin >> sa >> sb;

	reverse(all(sa)),reverse(all(sb));
	if(sa.back() == '-')	sa.pop_back(),mark = 0;
	if(sb.back() == '-')	sb.pop_back(),mark = 1;
	while(sa.length()<sb.length())	sa.push_back('0');
	while(sb.length()<sa.length())	sb.push_back('0');
	reverse(all(sa)),reverse(all(sb));


	if(sa<sb)	swap(sa,sb),mark^=1;

	for(auto x:sa)
		a.push_back(x-'0');
	for(auto x:sb)
		b.push_back(x-'0');
	reverse(all(a)),reverse(all(b));

	vector<int > c;
	for(int i=0;i<a.size();i++){
		printf("%d %d\n",a[i],b[i]);
		if(a[i]-b[i]<0){
			a[i+1]--;
			c.push_back(a[i]+10-b[i]);
		}else{
			c.push_back(a[i]-b[i]);
		}
	}
	while(!c.empty() && c.back() == 0)	c.pop_back();
	reverse(all(c));
	if(mark == 0)	cout << '-';
	for(auto x:c)
		cout << x;
}
void solve(){
	PII st,en;
	cin >> m >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i]+1;
		for(int j=1;j<=m;j++){
			if(a[i][j] == 'A')	st = {i,j};
			if(a[i][j] == 'B')	en = {i,j};
		}
	}
	get_all_dist();
	if(dist[st.first][st.second][en.first][en.second] == -1){
		cout << "-1 0\n";
		return ;
	}
	memset(dp,-1,sizeof dp);
	int minn = MAX_INT,step,nai,naj,nbi,nbj;
	que.push({st.first,st.second,en.first,en.second,0});
	while(!que.empty()){
		now = que.front();
		que.pop();
		if(minn>dist[now.ai][now.aj][now.bi][now.bj])
			minn = dist[now.ai][now.aj][now.bi][now.bj],step = now.w;
		for(int k=0;k<4;k++){
			nai = now.ai + dir4[0][k];
			naj = now.aj + dir4[1][k];
			nbi = now.bi + dirr4[0][k];
			nbj = now.bj + dirr4[1][k];
			if(nai<1 || naj<1 || nai>n || naj>m || a[nai][naj] == '#')	nai = now.ai,naj = now.aj;
			if(nbi<1 || nbj<1 || nbi>n || nbj>m || a[nbi][nbj] == '#')	nbi = now.bi,nbj = now.bj;
			if(dp[nai][naj][nbi][nbj]!=-1)	continue;
			dp[nai][naj][nbi][nbj] = now.w+1;
			que.push({nai,naj,nbi,nbj,now.w+1});
		}
	}
	cout << minn << ' ' << step << '\n';
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q = 1;
	minuss();
	// cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		// solve();
	}
	return 0;
}