/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
vector<int > g[MAXN];
queue<int > que;
int res[MAXN][MAXN],dis[MAXN],p[MAXN],s,t;
int augment(int u,int now){
    if(u==s)        return now;
    if(p[u]==-1)    return 0;
    int cap=augment(p[u],min(now,res[p[u]][u]));
    res[p[u]][u]-=cap;
    res[u][p[u]]+=cap;
    return cap;
}
int main(){
    int n,m,u,v,w,maxx=0;
    scanf("%d %d %d %d",&n,&m,&s,&t);
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back(v);
        g[v].push_back(u);
        res[u][v]=w;
    }
    while(1){
        memset(p,-1,sizeof p);
        for(int i=1;i<=n;i++)
            dis[i]=1e9;
        dis[s]=0;
        que.push(s);
        while(!que.empty()){
            u=que.front();
            que.pop();
            if(u==t)    break;
            for(int i=0;i<(int)g[u].size();i++){
                int v=g[u][i];
                if(res[u][v]==0)    continue;
                if(dis[v]>dis[u]+1){
                    dis[v]=dis[u]+1;
                    p[v]=u;
                    que.push(v);
                }
            }
        }
        int flow=augment(t,1e9);
        if(flow==0) break;
        maxx+=flow;
    }
    printf("%d\n",maxx);
    return 0;
}
