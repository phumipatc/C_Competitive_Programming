/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[5010],g2[5010];
stack<int > st;
int onstack[5010],low[5010],idx[5010],comp[5010],num[5010],lv[5010],sum[5010];
int countt = 1,group = 1,maxx = 0;
void SCC(int now){
    idx[now] = low[now] = countt++;
    onstack[now] = 1;
    st.push(now);
    for(auto x:g[now]){
        if(!idx[x]){
            SCC(x);
            low[now] = min(low[now],low[x]);
        }else if(onstack[x]){
            low[now] = min(low[now],idx[x]);
        }
    }
    if(low[now] == idx[now]){
        while(st.top()!=now){
            num[group]++;
            comp[st.top()] = group;
            onstack[st.top()] = 0;
            st.pop();
        }
        num[group]++;
        comp[now] = group++;
        onstack[now] = 0;
        st.pop();
    }
}
void dfs(int now,int level){
    lv[now] = level;
    for(auto x:g2[now]){
        if(level+1<=lv[x])  continue;
        dfs(x,level+1);
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
        if(idx[i])  continue;
        SCC(i);
    }
    for(int i=0;i<n;i++){
        for(auto x:g[i]){
            if(comp[x] == comp[i])  continue;
            g2[comp[i]].push_back(comp[x]);
        }
    }
    for(int i=0;i<n;i++){
        if(lv[comp[i]]) continue;
        dfs(comp[i],1);
    }
    for(int i=0;i<n;i++)
        sum[lv[comp[i]]]++;
    for(int i=1;i<=n && sum[i];i++)
        printf("%d ",sum[i]);
    printf("\n%d\n",lv[comp[0]]);
	return 0;
}
/*
4 5
0 1
1 2
2 0
2 3
1 3

4 3
2 1
2 0
1 3
*/