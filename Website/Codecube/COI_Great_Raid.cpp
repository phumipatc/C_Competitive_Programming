/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w;
};
A now;
priority_queue<A > heap;
int a[100010],dis[100010];
vector<int > g[100010];
int main(){
    int n,m,u,v;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        dis[i] = 1e9;
    }
    cin >> m;
    while(m--){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dis[1] = 0;
    heap.push({1,0});
    while(!heap.empty()){

    }
	return 0;
}
