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
vector<int > g[500005];
int deg[500005],dp[500005],mark[500005];
queue< A> que;
int main(){
    int n,m,u,v;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++,deg[v]++;
    }
    for(int i=1;i<=n;i++)
        if(deg[i] == 1 && i!=m)
            que.push({i,0});
    while(!que.empty()){
        A now = que.front();
        que.pop();
        for(auto x:g[now.v]){
            deg[x]--;
            if(deg[x]>0 && x!=m)
                dp[x]+=now.w+1;
            if(deg[x] == 1 && x!=m)
                que.push({x,dp[x]});
        }
    }
    if(deg[m]>1){
        int ans,maxx=-1;
        for(int i=1;i<=n;i++)
            if(maxx<dp[i] && i!=m)
                ans = i,maxx = dp[i];
        printf("%d\n%d\n",ans,maxx);
    }else{
        int now,ch = 0,nextt;
        for(int i=1;i<=n;i++)
            if(deg[i] == 3)
                now = i;
        que.push({g[now][0],0});
        nextt = g[now][0];
        mark[now] = 1;
        while(!que.empty()){
            A now = que.front();
            que.pop();
            if(now.v == m){
                ch = 1;
                break;
            }
            for(auto x:g[now.v]){
                if(!mark[x]){
                    mark[x] = 1;
                    que.push({x,0});
                }
            }
        }
        while(!que.empty()) que.pop();
        if(!ch){
            for(int i=0;i<g[now].size();i++)
                if(!mark[g[now][i]])
                    nextt = g[now][i];
        }
        if(g[now][0] == nextt)  que.push({g[now][1],dp[g[now][1]]}),deg[g[now][1]]--;
        else                    que.push({g[now][0],dp[g[now][0]]}),deg[g[now][0]]--;
        while(!que.empty()){
            A now=que.front();
            que.pop();
            for(auto x:g[now.v]){
                deg[x]--;
                if(deg[x] == 1 && x!=m){
                    dp[x]+=now.w+1;
                    que.push({x,dp[x]});
                }
            }
        }
        int ans,maxx=-1;
        for(int i=1;i<=n;i++)
            if(maxx<dp[i] && i!=m)
                maxx = dp[i],ans = i;
        printf("%d\n%d\n",ans,maxx);
    }
    return 0;
}
