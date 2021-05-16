/*
	Task	: PN_Node_Sort
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 16 May 2021 [11:44]
	Algo	: 
	Status	: 
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x),end(x)
#define allst(x,y) (x).begin()+y,(x).end()
#define rmdup(x) (x).resize(unique((x).begin(),(x).end())-(x).begin())
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
const int N = 50010;
vector< int> g[N];
int in[N],ans[N],change[N];
void solve(){
	int n,m,u,v,st,idx;
	priority_queue< int,vector<int>,greater<int>> heap;
	cin >> n >> m;
    for(int i=1;i<=m;i++){
		cin >> u >> v;
        g[v].push_back(u);
        in[u]++;
    }
    for(int i=1;i<=n;i++)
        if(!in[i])
            heap.push(i);
    idx = 0;
    while(!heap.empty()){
        int now = heap.top();
        if(heap.size()>=2)  change[idx] = 1;
        heap.pop();
        ans[idx++] = now;
        for(int i=0;i<g[now].size();i++){
            in[g[now][i]]--;
            if(!in[g[now][i]])
                heap.push(g[now][i]);
        }
    }
    int ch = 0;
    for(int i=idx -1;i>=0;i--)
        if(change[i] && !ch)
            swap(ans[i],ans[i+1]),ch = 1;
    if(idx!=n){
		cout << "Never\n";
        goto reset;
    }else if(!ch)
		cout << "Same ";
    else
		cout << "Different ";
    for(int i=0;i<idx;i++)
		cout << ans[i] << ' ';
	printf("\n");
	reset:;
	rep(i,1,n+1)	g[i].clear();
	memset(in,0,sizeof in);
	memset(ans,0,sizeof ans);
	memset(change,0,sizeof change);
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