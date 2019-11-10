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
int in[500005],dp[500005],mark[500005];
queue< A> que;
int main(){
    int n,m,u,v;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        in[u]++,in[v]++;
    }
    for(int i=1;i<=n;i++)
        if(in[i] == 1 && i!=m)
            que.push({i,0});
    while(!que.empty()){
        A now = que.front();
        que.pop();
        for(int i=0;i<g[now.v].size();i++){
            in[g[now.v][i]]--;
            if(in[g[now.v][i]]>0 && g[now.v][i]!=m)
                dp[g[now.v][i]]+=now.w+1;
            if(in[g[now.v][i]] == 1 && g[now.v][i]!=m)
                que.push({g[now.v][i],dp[g[now.v][i]]});
        }
    }
    if(in[m]>1){
        int ans,maxx=-1;
        for(int i=1;i<=n;i++)
            if(maxx<dp[i] && i!=m)
                ans = i,maxx = dp[i];
        printf("%d\n%d\n",ans,maxx);
    }else{
        int node,ch = 0,nextt;
        for(int i=1;i<=n;i++)
            if(in[i] == 3)
                node = i;
        que.push({g[node][0],0});
        nextt = g[node][0];
        mark[node] = 1;
        while(!que.empty()){
            A now = que.front();
            que.pop();
            if(now.v == m){
                ch = 1;
                break;
            }
            for(int i=0;i<g[now.v].size();i++){
                if(!mark[g[now.v][i]]){
                    mark[g[now.v][i]] = 1;
                    que.push({g[now.v][i],0});
                }
            }
        }
        while(!que.empty()) que.pop();
        if(!ch)
            for(int i=0;i<g[node].size();i++)
                if(!mark[g[node][i]])
                    nextt = g[node][i];
        if(g[node][0] == nextt)
            que.push({g[node][1],dp[g[node][1]]}),in[g[node][1]]--;
        else
            que.push({g[node][0],dp[g[node][0]]}),in[g[node][0]]--;
        while(!que.empty()){
            A now=que.front();
            que.pop();
            for(int i=0;i<g[now.v].size();i++){
                in[g[now.v][i]]--;
                if(in[g[now.v][i]] == 1 && g[now.v][i]!=m){
                    dp[g[now.v][i]]+=now.w+1;
                    que.push({g[now.v][i],dp[g[now.v][i]]});
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
