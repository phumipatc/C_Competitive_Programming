/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[100100];
int mark[100100];
int dfs(int now,int state){
    if(mark[now]){
        if(mark[now] == state)  return 1;
        else                    return 0;
    }
    mark[now] = state;
    for(auto &x:g[now])
        if(dfs(x,3-state) == 0)
            return 0;
}
int main(){
    int q,n,m,u,v;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=m;i++){
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(dfs(1,1))    printf("yes\n");
        else            printf("no\n");
        for(int i=1;i<=n;i++)
            g[i].clear();
        memset(mark,0,sizeof mark);
    }
    return 0;
}
