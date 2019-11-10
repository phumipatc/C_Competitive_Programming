/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[100010],inv[100010];
stack<int > st;
int mark[100010],comp[100010];
int countt = 1;
void dfs(int now){
    mark[now] = 1;
    for(auto x:g[now]){
        if(mark[x]) continue;
        dfs(x);
    }
    st.push(now);
}
void dfs2(int now){
    mark[now] = 1;
    comp[now] = countt;
    for(auto x:inv[now]){
        if(mark[x]) continue;
        dfs2(x);
    }
}
int main(){
    int n,m,k,temp,num,u,v;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&temp);
        while(temp--){
            scanf("%d",&num);
            g[i].push_back(num);
            inv[num].push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(mark[i]) continue;
        dfs(i);
    }
    memset(mark,0,sizeof mark);
    while(!st.empty()){
        if(mark[st.top()] == 0){
            dfs2(st.top());
            countt++;
        }
        st.pop();
    }
    while(k--){
        scanf("%d %d",&u,&v);
        if(comp[u] == comp[v])  printf("yes\n");
        else                    printf("no\n");
    }
	return 0;
}
