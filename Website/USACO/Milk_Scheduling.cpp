/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[10010];
int val[10010],in[10010],ans[10010];
queue<int > que;
int main(){
    freopen("msched.in","r",stdin);
    freopen("msched.out","w",stdout);
    int n,m,u,v,now;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&val[i]);
    while(m--){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        in[v]++;
    }
    for(int i=1;i<=n;i++){
        if(in[i])   continue;
        que.push(i);
    }
    int maxx = 0;
    while(!que.empty()){
        now = que.front();
        que.pop();
        ans[now]+=val[now];
        maxx = max(maxx,ans[now]);
        for(auto x:g[now]){
            ans[x] = max(ans[x],ans[now]);
            in[x]--;
            if(in[x])   continue;
            que.push(x);
        }
    }
    printf("%d\n",maxx);
    return 0;
}