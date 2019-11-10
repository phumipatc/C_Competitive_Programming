/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w1,w2;
    bool operator < (const A&o) const{
        if(v!=o.v)  return v>o.v;
        else        return abs(w1-w2)<abs(o.w1-o.w2);
    }
};
priority_queue<A > heap;
int onstack[310],num[310],low[310],comp[310];
int gr = 1,countt = 1;
vector<int > g[310];
stack<int > st;
pair<int ,int > p[310][310];
void dfs(int now){
    num[now] = low[now] = countt++;
    onstack[now] = 1;
    st.push(now);
    for(auto x:g[now]){
        if(!num[x]){
            dfs(x);
            low[now] = min(low[now],low[x]);
        }else if(onstack[x]){
            low[now] = min(low[now],num[x]);
        }
    }
    if(num[now] == low[now]){
        while(!st.empty() && st.top()!=now){
            comp[st.top()] = gr;
            onstack[st.top()] = 0;
            st.pop();
        }
        comp[st.top()] = gr++;
        onstack[st.top()] = 0;
        st.pop();
    }
}
int main(){
    int n,m,u,v,w1,w2;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d %d %d",&u,&v,&w1,&w2);
        g[u].push_back(v);
        p[u][v] = {w1,w2};
    }
    for(int i=1;i<=n;i++){
        if(num[i])  continue;
        dfs(i);
    }
	return 0;
}
