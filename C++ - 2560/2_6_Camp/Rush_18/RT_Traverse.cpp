/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[10];
int in[10],ans,n,mark[10];
void dfs(int now,int countt){
    if(in[now] == 1 && now!=1){
        if(countt == n) ans++;
        return ;
    }
    mark[now] = 1;
    int c = 0;
    for(int i=0;i<g[now].size();i++){
        if(!mark[g[now][i]])
            dfs(g[now][i],countt+1);
        if(mark[g[now][i]]) c++;
    }
    mark[now] = 0;
    if(c == g[now].size()){
        if(countt == n) ans++;
        return ;
    }
}
int main(){
    int u,v,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
        in[u]++,in[v]++;
    }
    dfs(1,1);
    printf("%d\n",ans);
    return 0;
}
