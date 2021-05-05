/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Heap, FW
	Status	: Finished
*/
#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define allst(x,y) (x).begin()+y,(x).end()
#define decp(x)	fixed << setprecision(x)
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
int tree[100010];
void upd(int idx,int v){
	while(idx<=100003){
		tree[idx]+=v;
		idx+= idx & -idx;
	}
}
int qr(int idx){
	int sum = 0;
	while(idx>0){
		sum+=tree[idx];
		idx-= idx & -idx;
	}
	return sum;
}
struct A{
	int id,p;
	bool operator < (const A&o) const{
		return p>o.p;
	}
};
A now;
priority_queue<A > heap;
int v[200010];
void solve(){
	int m,opr,id,p,cnt = 0;
	cin >> m;
	while(m--){
		cin >> opr;
		if(opr == 1){
			cin >> p;
			v[++cnt] = p;
			heap.push({cnt,p});
			upd(p,1);
		}else if(opr == 2){
			if(heap.empty())	cout << "0\n";
			else{
				now = heap.top();
				heap.pop();
				cout << now.id << '\n';
				upd(now.p,-1);
			}
		}else{
			cin >> id;
			cout << qr(v[id]-1) << '\n';
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