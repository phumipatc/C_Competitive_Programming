/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct A{
    int v,w;
};
A now,Q[200010];
vector<int > g[100010][2],ans;
queue<A > que;
int mark[100010],dis[100010][2];
void bfs(){
    while(!que.empty()){
        now = que.front();
        que.pop();
        for(auto x:g[now.v][now.w]){
            if(mark[x])         continue;
            if(dis[x][now.w])   continue;
            dis[x][now.w] = 1;
            que.push({x,now.w});
        }
    }
}
int main(){
    int n,m,q,u,v;
    scanf("%d %d %d",&n,&m,&q);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&u,&v);
        if(u == v)  continue;
        g[u][0].push_back(v);
        g[v][1].push_back(u);
    }
    for(int i=1;i<=q;i++){
        scanf("%d %d",&Q[i].v,&Q[i].w);
        if(Q[i].v == 1)
            mark[Q[i].w] = 1;
    }
    dis[1][0] = dis[n][1] = 1;
    que.push({1,0});
    que.push({n,1});
    bfs();
    for(int i=q;i>=1;i--){
        if(Q[i].v == 1){
            mark[Q[i].w] = 0;
            for(auto x:g[Q[i].w][0]){
                if(mark[x]) continue;
                if(dis[x][0])   que.push({x,0});
                if(dis[x][1])   que.push({x,1});
            }
            for(auto x:g[Q[i].w][1]){
                if(mark[x]) continue;
                if(dis[x][0])   que.push({x,0});
                if(dis[x][1])   que.push({x,1});
            }
            bfs();
        }else{
            ans.push_back(dis[Q[i].w][0]&dis[Q[i].w][1]);
        }
    }
    for(int i=ans.size()-1;i>=0;i--)
        printf("%d\n",ans[i]);
    return 0;
}
/*
5 6 8
1 2
2 3
2 4
4 3
1 3
3 5
2 4
1 2
2 4
2 3
2 5
1 3
2 4
2 3
*/