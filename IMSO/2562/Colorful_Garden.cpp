/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000003
using namespace std;
vector<int > g[1010];
int col[1010],mark[1010][1030];
int c;
int dfs(int now,int w){
    // printf("processing: %d %d\n",now,w);
    if(mark[now][w]!=-1)  return mark[now][w];
    mark[now][w] = 0;
    for(auto x:g[now])
        if((1<<col[x])&w)
            mark[now][w]+=dfs(x,w^(1<<col[x])),mark[now][w]%=MOD;
    // printf("%d %d %d\n",now,w,mark[now][w]);
    return mark[now][w];
}
int main(){
    int n,m,u,v;
    scanf("%d %d %d",&n,&m,&c);
    for(int i=0;i<n;i++)
        scanf("%d",&col[i]);
    while(m--){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    memset(mark,-1,sizeof mark);
    for(int i=0;i<n;i++)
        mark[i][0] = 1;
    for(int i=0;i<n;i++)
        ans+=dfs(i,((1<<c)-1)^(1<<col[i])),ans%=MOD;
    printf("%d\n",ans);
    return 0;
}