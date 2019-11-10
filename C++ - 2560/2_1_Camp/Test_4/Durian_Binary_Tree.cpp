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
vector< A> g[110];
int mark[110],l[110],r[110],weight[110],mic[110][110];
void dfs(int now){
    mark[now]=1;
    for(int i=0;i<g[now].size();i++){
        if(mark[g[now][i].v])   continue;
        if(l[now]==0)   l[now]=g[now][i].v;
        else            r[now]=g[now][i].v;
        weight[g[now][i].v]=g[now][i].w;
        dfs(g[now][i].v);
    }
}
int tree(int now,int k){
    int maxx=-1;
    if(k==0)                return mic[now][k]=0;
    if(mic[now][k]!=-1)     return mic[now][k];
    for(int i=0;i<k;i++)
        maxx=max(maxx,tree(l[now],i)+tree(r[now],k-i-1));
    return mic[now][k]=maxx+weight[now];
}
int main(){
    int n,k,i,u,v,w;
    scanf("%d %d",&n,&k);
    for(i=1;i<n;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dfs(1);
    memset(mic,-1,sizeof mic);
    memset(mark,0,sizeof mark);
    printf("%d\n",tree(1,k+1));
    return 0;
}
/*
5 2
1 3 1
1 4 10
2 3 20
3 5 20
*/
