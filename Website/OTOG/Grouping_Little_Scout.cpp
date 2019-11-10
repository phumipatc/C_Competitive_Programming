/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[1010];
stack<int > st;
int idx[1010],low[1010],onstack[1010];
int maxx = 0,countt = 1;
void dfs(int now,int p){
    idx[now] = low[now] = countt++;
    onstack[now] = 1;
    st.push(now);
    for(auto x:g[now]){
        if(x == p)  continue;
        if(!idx[x]){
            dfs(x,now);
            low[now] = min(low[now],low[x]);
        }else if(onstack[x]){
            low[now] = min(low[now],idx[x]);
        }
    }
    if(low[now] == idx[now]){
        while(st.top()!=now){
            onstack[st.top()] = 0;
            st.pop();
        }
        onstack[now] = 0;
        st.pop();
        maxx++;
    }
}
int main(){
    int n,m,u,v;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(idx[i])  continue;
        dfs(i,0);
    }
    printf("%d\n",maxx);
	return 0;
}