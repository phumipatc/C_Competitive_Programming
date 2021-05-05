/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Heap
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
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
struct A{
	int id,w,v,d,x;
	bool operator < (const A&o) const{
		return w>o.w;
	}
};
priority_queue<A > heap;
struct B{
	int id,w,v,d,x;
	bool operator < (const B&o) const{
		return d>o.d;
	}
};
priority_queue<B > heap2;
int mark[200010];
void solve(){
	int n,m,w,v,d,x,opr,t;
	cin >> n >> m;
	for(int i=1;i<=n+m;i++){
		cin >> opr;
		if(opr == 1){
			cin >> t;
			if(t == 1){
				cin >> w >> v;
				heap.push({i,w,v});
			}else if(t == 2){
				cin >> w >> v >> d;
				heap.push({i,w,v,d});
			}else if(t == 3){
				cin >> w >> v >> d >> x;
				heap.push({i,w,v,d,x});
				heap2.push({i,w,v,d,x});
			}
		}else if(opr == 2){
			int ch = 0;
			while(!heap2.empty()){
				B now = heap2.top();
				if(now.d>=i)	break;
				heap2.pop();
				if(mark[now.id])	continue;
				mark[now.id] = 1;
				heap.push({now.id+200000,now.x,now.v});
			}
			while(!heap.empty()){
				A now = heap.top();
				heap.pop();
				if(now.id<=200000 && mark[now.id])	continue;
				if(now.d && now.d<i)				continue;
				if(now.id<=200000)
					mark[now.id] = 1;
				cout << now.v << '\n';
				ch = 1;
				break;
			}
			if(!ch)	cout << "0\n";
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q = 1;
	// cin >> q;
	while(q--){
		solve();
	}
	return 0;
}