/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w;
};
vector< A> g[100100];
int XOR[100100],mark[100100];
void dfs(int now,int state){
    mark[now]=1;
    XOR[now]=state;
    for(int i=0;i<g[now].size();i++)
        if(mark[g[now][i].v]==0)
            dfs(g[now][i].v,state^g[now][i].w);
}
int main(){
    int n,m,u,v,w;
    scanf("%d %d",&n,&m);
    for(int i=1;i<n;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dfs(1,0);
    while(m--){
        scanf("%d %d",&u,&v);
        printf("%d\n",XOR[u]^XOR[v]);
    }
    return 0;
}
