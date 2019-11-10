 /*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector< int> g[100100];
int mark[100100],color[100100];
int dfs(int u,int now){
    if(mark[u]==1 && color[u]==now)
        return 1;
    if(mark[u]==1 && color[u]!=now)
        return 0;
    mark[u]=1;
    color[u]=now;
    int i;
    for(i=0;i<g[u].size();i++){
        if(dfs(g[u][i],3-now)==0)
            return 0;
    }
    return 1;
}
int main(){
    int q,n,m,i,u,v;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++){
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(dfs(1,1)==1)
            printf("yes\n");
        else
            printf("no\n");
        for(i=0;i<=n;i++)
            g[i].clear();
        memset(mark,0,sizeof mark);
        memset(color,0,sizeof color);
    }
return 0;
}
