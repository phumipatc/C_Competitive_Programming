/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[100100];
int c[100100];
bool dfs(int now,int col){
    if(c[now] && c[now]!=col)   return false;
    if(c[now])                  return true;
    c[now] = col;
    for(auto &x:g[now]){
        if(!dfs(x,3-col))
            return false;
    }
    return true;
}
int main(){
    int q,n,m,u,v;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        while(m--){
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(dfs(1,1))    printf("yes\n");
        else            printf("no\n");
        for(int i=1;i<=n;i++)
            g[i].clear();
        memset(c,0,sizeof c);
    }
	return 0;
}
