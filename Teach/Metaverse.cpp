#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i <= (b); ++i)
#define repr(i, a, b) for(int i = a; i >= (b); --i)
#define repl(i, a, b) for(LL i = a; i <= (b); ++i)
#define reprl(i, a, b) for(LL i = a; i >= (b); --i)
#define all(x) begin(x),end(x)
#define allst(x,y) (x).begin()+y,(x).end()
#define rmdup(x) sort(all(x)),(x).resize(unique((x).begin(),(x).end())-(x).begin())
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
const int N = 40010;
struct A{
	int v,w,state;
	bool operator < (const A&o) const{
		if(w!=o.w)	return w>o.w;
		else		return state>o.state;
	}
};
vector<pair<int,int> > points;
int dis[N],ch[N];
void init(){
	
}
int calc(pair<pair<int,int>, pair<int,int> > x){
	return abs(x.first.first-x.second.first) + abs(x.first.second-x.second.second);
}
void f(int x){
	dis[1]=min(dis[1],dis[0]+calc({points[0],points[1]}));
	for(int j=2;j<points.size();j+=2){
		dis[j]=min(dis[j],dis[0]+calc({points[0],points[j]}));
	}
	for(int i=3;i<points.size();i+=2){
		if(ch[i]!=x)continue;
		dis[1]=min(dis[1],dis[i]+calc({points[i],points[1]}));
		for(int j=0;j<points.size();j+=2){
			dis[j]=min(dis[j],dis[i]+calc({points[i],points[j]}));
		}
	}
}
void solve(){
	int m,n,k,p,x1,y1,x2,y2;
	scanf("%d %d %d %d",&m,&n,&k,&p);
	points.push_back({1,1});
	points.push_back({m,n});
	rep(i,1,k){
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		points.push_back({x1,y1});
		points.push_back({x2,y2});
	}
	fill(dis,dis+N,1e9);
	dis[0] = 0;
	memset(ch,-1,sizeof ch);
	f(0);
	int ans1=dis[1];
	int ans2=0;
	for(int i=1;i<=p;i++){
		for(int j=2;j<points.size();j+=2){
			if(dis[j]<dis[j+1]){
				dis[j+1]=dis[j];
				ch[j+1]=i;
			}
			dis[j+1]=min(dis[j],dis[j+1]);
		}
		f(i);
		if(dis[1]<ans1){
			ans1=dis[1];
			ans2=i;
		}
	}
	printf("%d %d\n",ans1,ans2);
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	// freopen("d:/Code/C_Programming/input.in","r",stdin);
	init();
	int q = 1;
	// cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}