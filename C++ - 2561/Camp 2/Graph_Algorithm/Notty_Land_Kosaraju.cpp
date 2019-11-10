/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[100010],gt[100010];
int mark[100010],comp[100010],countt = 1;
stack<int > st;
void dfs(int now){
    mark[now] = 1;
    for(auto x:g[now]){
        if(mark[x]) continue;
        dfs(x);
    }
    st.push(now);
}
void dfs2(int now){
    comp[now] = countt;
    mark[now] = 1;
    for(auto x:gt[now]){
        if(mark[x]) continue;
        dfs2(x);
    }
}
int main(){
    int n,m,k,u,v,temp;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&temp);
        while(temp--){
            scanf("%d",&v);
            g[i].push_back(v);
            gt[v].push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(!mark[i]){
            dfs(i);
        }
    }
    memset(mark,0,sizeof mark);
    while(!st.empty()){
        if(mark[st.top()]){
            st.pop();
            continue;
        }
        dfs2(st.top());
        st.pop();
        countt++;
    }
    while(k--){
        scanf("%d %d",&u,&v);
        if(comp[u] == comp[v])  printf("yes\n");
        else                    printf("no\n");
    }
	return 0;
}
