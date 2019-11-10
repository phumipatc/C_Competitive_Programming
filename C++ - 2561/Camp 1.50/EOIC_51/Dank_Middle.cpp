/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[10100];
int deg[10100],mark[10100],countt = 0,n;
void dfs(int now){
    if(mark[now])   return ;
    mark[now] = 1;
    countt++;
    if(countt == (n+1)/2){
        printf("%d\n",now);
        exit(0);
    }
    for(auto &x:g[now])
        dfs(x);
}
int main(){
    int u,v;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++,deg[v]++;
    }
    for(int i=1;i<=n;i++)
        if(deg[i] == 1)
            dfs(i);
	return 0;
}
