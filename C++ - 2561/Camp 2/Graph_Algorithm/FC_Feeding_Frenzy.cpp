/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[5010],gt[5010];
stack<int > st;
int mark[5010],low[5010],idx[5010],comp[5010],onstack[5010];
int group = 1,countt = 1,lv[5010],c[5010];
void dfs(int now){
    idx[now] = low[now] = group++;
    mark[now] = 1;
    onstack[now] = 1;
    st.push(now);
    for(auto x:g[now]){
        if(!mark[x]){
            dfs(x);
            low[now] = min(low[now],low[x]);
        }else if(onstack[x]){
            low[now] = min(low[now],idx[x]);
        }
    }
    if(idx[now] == low[now]){
        while(!st.empty() && st.top()!=now){
            onstack[st.top()] = 0;
            comp[st.top()] = countt;
            st.pop();
        }
        st.pop();
        onstack[now] = 0;
        comp[now] = countt++;
    }
}
void dfs2(int u,int lvl){
    for(auto x:gt[u]){
        if(lvl+1<=lv[x])    continue;
        lv[x] = lvl+1;
        dfs2(x,lvl+1);
    }
}
int main(){
    int n,m,u,v;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
    }
    for(int i=0;i<n;i++){
        if(mark[i]) continue;
        dfs(i);
    }
    for(int i=0;i<n;i++){
        for(auto x:g[i]){
            if(comp[i]!=comp[x]){
                gt[comp[i]].push_back(comp[x]);
            }
        }
    }
    int maxx = 1;
    for(int i=0;i<n;i++){
        if(lv[comp[i]]) continue;
        lv[comp[i]] = 1;
        dfs2(comp[i],1);
    }
    for(int i=0;i<n;i++)
        c[lv[comp[i]]]++;
    for(int i=1;i<=n && c[i]>0;i++)
        printf("%d ",c[i]);
    printf("\n%d\n",lv[comp[0]]);
	return 0;
}
