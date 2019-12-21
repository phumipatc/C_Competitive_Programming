/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct A{
    int v,w,state;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
vector<A > g[50010];
priority_queue<A > heap;
char xmas[10],a[50010];
int num[50010],dis[50010][20];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,m;
    cin >> n >> m >> xmas >> a+2;
    int need = 0;
    for(int i=0;i<4;i++)
        if(xmas[i] == '_')
            need|=(1<<i);
    for(int i=2;i<=n;i++){
        switch (a[i])
        {
            case 'X':   a[i] = 1;   break;
            case 'M':   a[i] = 2;   break;
            case 'A':   a[i] = 4;   break;
            case 'S':   a[i] = 8;   break;
            default:    a[i] = 0;
        }
    }
    int u,v,w;
    while(m--){
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<16;j++)
            dis[i][j] = 1e9;
    if(a[n] == 0)   dis[n][0] = 0,heap.push({n,0,0});
    else            dis[n][1<<a[n]] = 0,heap.push({n,0,a[n]});
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        if(now.v == 1){
            if((need & now.state) != need)  continue;
            cout << now.w << '\n';
            break;
        }
        for(auto x:g[now.v]){
            if(dis[x.v][now.state|a[x.v]]<=now.w+x.w)  continue;
            dis[x.v][now.state|a[x.v]] = now.w+x.w;
            heap.push({x.v,now.w+x.w,now.state|a[x.v]});
        }
    }
    return 0;
}