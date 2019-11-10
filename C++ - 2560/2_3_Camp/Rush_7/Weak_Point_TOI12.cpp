/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[500100];
int countt;
int mark[500100];
void dfs(int now,int stop){
    if(mark[now])   return ;
    mark[now]=1;
    for(int i=0;i<g[now].size();i++)
        if(!mark[g[now][i]] && g[now][i]!=stop)
            countt++,dfs(g[now][i],stop);
}
int main()
{
    int n,i,st,u,v,maxx=-1,ans;
    scanf("%d %d",&n,&st);
    for(i=1;i<=n;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(i=1;i<=n;i++){
        if(i!=st){
            countt=1;
            dfs(st,i);
            if(n-countt-1>maxx)
                maxx=n-countt-1,ans=i;
            memset(mark,0,sizeof mark);
        }
    }
    printf("%d\n%d\n",ans,maxx);
    return 0;
}
