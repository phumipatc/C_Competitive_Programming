/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[100100];
queue< pair<int ,int > > que;
int in[100010],ans[100010],mark[100010];
void dfs(int now){
    mark[now] = 1;
    for(auto x:g[now]){
        if(mark[x]) continue;
        in[now]++;
        dfs(x);
    }
}
int main(){
    int n,i,u,v,idx=0;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    for(i=1;i<=n;i++)
        if(in[i]==0)
            que.push({i,1});
    while(!que.empty()){
        int a = que.front().first;
        int b = que.front().second;
        que.pop();
        for(auto x:g[a]){
            if(in[x] == 0)    continue;
            in[x]--;
            if(x == 1){
                if(!in[x])  ans[idx++] = b+1;
                else        ans[idx++] = b;
                continue;
            }
            if(!in[x])  que.push({x,b+1});
            else        ans[idx++] = b;
        }
    }
    sort(ans,ans+idx);
    printf("%d\n",idx);
    for(i=idx-1;i>=0;i--)
        printf("%d\n",ans[i]);
    return 0;
}
