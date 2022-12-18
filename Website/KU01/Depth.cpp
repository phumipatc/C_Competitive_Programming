/*
	Task	: depth
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 18 December 2022 [10:08]
	Algo	: 
	Status	: 
*/
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
const int N = 1e5+10;
// struct A{
// 	int depth,id,l,r;
// 	bool operator < (const A&o) const{
// 		if(depth != o. depth)	return depth < o.depth;
// 		else if(id != o.id)		return id < o.id;
// 		else if(l != o.l)		return l < o.l;
// 		else 					return r < o.r;
// 	}
// };
// set<pair<int ,pair<int ,pair<int ,int > > > > s;
// int len[N],h[N],ans[N];
void init(){
	
}
void solve(){
	int n,q,d,mx = 0;
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> d >> d;
		// h[i] = h[i-1] + d;
		// mx = max(mx,h[i]);
		// s.insert({h[i],{i,{i-1,i+1}}});
	}
	// while(!s.empty()){
	// 	auto en = s.end();
	// 	en--;
	// 	auto v = *en;
	// 	s.erase(en);
	// 	ans[v.depth] = max(ans[v.depth],len[v.id]);
	// 	//merge
	// 	if(v.l != 0 && v.r != n+1){
	// 		//have left and right
	// 		auto it = s.lower_bound({h[v.l],v.l,0,0});
	// 		auto it2 = s.lower_bound({h[v.r],v.r,0,0});
	// 		if(h[v.l] > h[v.r]){
	// 			//left is higher
	// 			auto tmp = *it;
	// 			s.erase(it);
	// 			s.insert({h[v.l],v.l,tmp.l,v.r});
	// 			len[v.l]+=len[v.id];
	// 		}else if(h[v.l] < h[v.r]){
	// 			//right is higher
	// 			auto tmp = *it2;
	// 			s.erase(it2);
	// 			s.insert({h[v.r],v.r,v.l,tmp.r});
	// 			len[v.r]+=len[v.id];
	// 		}else{
	// 			//same height
	// 			auto tmp = *it;
	// 			auto tmp2 = *it2;
	// 			s.erase(it);
	// 			s.erase(it2);
	// 			s.insert({h[v.l],v.l,tmp.l,tmp2.r});
	// 			len[v.l]+=len[v.id] + len[v.r];
	// 		}
	// 	}else if(v.l == 0 && v.r != n+1){
	// 		//have right
	// 		auto it = s.lower_bound({h[v.r],v.r,0,0});
	// 		auto tmp = *it;
	// 		s.erase(it);
	// 		s.insert({h[v.r],v.r,v.l,tmp.r});
	// 		len[v.r]+=len[v.id];
	// 	}else if(v.l != 0 && v.r == n+1){
	// 		//have left
	// 		auto it = s.lower_bound({h[v.l],v.l,0,0});
	// 		auto tmp = *it;
	// 		s.erase(it);
	// 		s.insert({h[v.l],v.l,tmp.l,v.r});
	// 		len[v.l]+=len[v.id];
	// 	}else{
	// 		//no left and right
	// 		break;
	// 	}
	// }
	// ans[0] = ans[1] + 1;
	// for(int i=0;i<=mx/2;i++)
	// 	swap(ans[i],ans[mx-i]);
	while(q--){
		int x;
		cin >> x;
	// 	int idx = lower_bound(ans,ans+mx+1,x) - ans;
	// 	cout << mx-idx << '\n';
	}
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