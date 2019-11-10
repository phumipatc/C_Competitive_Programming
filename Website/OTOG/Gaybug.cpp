/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[100010];
int col[100010];
int dfs(int now,int c){
    if(col[now]){
        if(col[now] == c)   return 1;
        else                return 0;
    }
    col[now] = c;
    for(auto x:g[now]){
        if(dfs(x,3-c) == 0) return 0;
    }
    return 1;
}
int main(){
    int n,m,u,v;
    cin >> n >> m;
    while(m--){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(col[i])  continue;
        if(dfs(i,1) == 0){
            cout << "Gay found!" << endl;
            return 0;
        }
    }
    cout << "Gay not found!" << endl;
	return 0;
}