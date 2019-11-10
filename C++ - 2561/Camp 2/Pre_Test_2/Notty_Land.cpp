/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
stack<int > st;
vector<int > g[100010];
int low[100010],idx[100010],mark[100010],onstack[100010],comp[100010],countt = 1,gr = 1;
void dfs(int u){
    idx[u] = low[u] = countt++;
    mark[u] = 1;
    onstack[u] = 1;
    st.push(u);
    for(auto x:g[u]){
        if(!mark[x]){
            dfs(x);
            low[u] = min(low[u],low[x]);
        }else if(onstack[x]){
            low[u] = min(low[u],idx[x]);
        }
    }
    if(idx[u] == low[u]){
        while(!st.empty() && st.top()!=u){
            comp[st.top()] = gr;
            onstack[st.top()] = 0;
            st.pop();
        }
        comp[u] = gr++;
        onstack[st.top()] = 0;
        st.pop();
    }
}
int main(){
    int n,m,k,u,v;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&u);
        while(u--){
            scanf("%d",&v);
            g[i].push_back(v);
        }
    }
    for(int i=1;i<=n;i++){
        if(mark[i]) continue;
        dfs(i);
    }
    while(k--){
        scanf("%d %d",&u,&v);
        if(comp[u] == comp[v])  printf("yes\n");
        else                    printf("no\n");
    }
	return 0;
}
