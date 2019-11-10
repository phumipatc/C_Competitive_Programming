/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,i,p;
};
A now;
vector<int > g[500010];
stack<A > dfs;
stack<int > st;
int idx[500010],low[500010],mark[500010],onstack[500010],comp[500010];
int main(){
    int n,m,countt = 1,group = 1,j,u,v;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(mark[i]) continue;
        dfs.push({i,-1,0});
        while(!dfs.empty()){
            now = dfs.top();
            dfs.pop();
            mark[now.u] = 1;
            if(now.i == -1) idx[now.u] = low[now.u] = countt++,st.push(now.u),onstack[now.u] = 1;
            else            low[now.u] = min(low[now.u],low[g[now.u][now.i]]);
            for(j=now.i+1;j<g[now.u].size();j++){
                if(g[now.u][j] == now.p)    continue;
                if(!mark[g[now.u][j]]){
                    dfs.push({now.u,j,now.p});
                    dfs.push({g[now.u][j],-1,now.u});
                    break;
                }else if(onstack[g[now.u][j]]){
                    low[now.u] = min(low[now.u],idx[g[now.u][j]]);
                }
            }
            if(j == g[now.u].size()){
                if(idx[now.u] == low[now.u]){
                    while(!st.empty() && st.top()!=now.u){
                        comp[st.top()] = group;
                        onstack[st.top()] = 0;
                        st.pop();
                    }
                    comp[now.u] = group++;
                    onstack[now.u] = 0;
                    st.pop();
                }
            }
        }
    }
    printf("%d\n",group-1);
	return 0;
}
/*
19 24
1 2
2 4
4 3
3 1
2 5
5 6
6 7
7 8
8 6
4 10
10 9
9 17
17 16
9 16
17 18
18 16
16 19
10 11
11 13
13 15
15 11
15 12
12 14
14 15
*/
