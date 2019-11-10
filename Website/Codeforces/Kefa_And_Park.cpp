/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[100010];
int val[100010],mark[100010];
int ans = 0,m;
void dfs(int now,int state){
    mark[now] = 1;
    int ch = 1;
    // printf("%d %d\n",now,state);
    for(auto x:g[now]){
        if(mark[x]) continue;
        ch = 0;
        if(val[x] && state+1<=m)    dfs(x,state+1);
        else if(!val[x])            dfs(x,0);
    }
    if(ch)  ans++;
}
int main(){
    int n,u,v;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> val[i];
    for(int i=1;i<n;i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,val[1]);
    cout << ans << endl;
	return 0;
}
