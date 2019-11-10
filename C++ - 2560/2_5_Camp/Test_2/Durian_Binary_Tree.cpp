/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int a,b;
};
A tree[150];
vector< A> g[150];
int weight[150],mark[150],mem[150][150];
void dfs(int now){
    mark[now] = 1;
    for(int i=0;i<g[now].size();i++){
        if(!mark[g[now][i].a]){
            weight[g[now][i].a] = g[now][i].b;
            if(!tree[now].a)        tree[now].a = g[now][i].a;
            else if(!tree[now].b)   tree[now].b = g[now][i].a;
            dfs(g[now][i].a);
        }
    }
}
int choose(int now,int k){
    if(now == 0)        return 0;
    if(k == 0)          return 0;
    if(mem[now][k]!=-1) return mem[now][k];
    int maxx = -1;
    for(int i=0;i<k;i++)
        maxx = max(maxx,choose(tree[now].a,i)+choose(tree[now].b,k-i-1));
    return mem[now][k] = maxx+weight[now];
}
int main(){
    int n,m,u,v,w,ans = 0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<n;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dfs(1);
    memset(mem,-1,sizeof mem);
    ans = choose(1,m+1);
    printf("%d\n",ans);
    return 0;
}
