/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct A{
    int v,w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
vector<A > g[10010];
priority_queue<A > heap;
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,m,st,en,u,v,w;
    cin >> n >> m >> st >> en;
    while(m--){
        cin >> u >> v >> w;
        g[u].push_back({v,w});
    }
    heap.push({st,0});
    int minn = 1e9;
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        if(now.v == en){
            if(minn == 1e9){
                minn = now.w;
                continue;
            }
            if(minn == now.w)   continue;
            cout << now.w << "\n";
            break;
        }
        for(auto x:g[now.v]){
            heap.push({x.v,now.w+x.w});
        }
    }
    return 0;
}