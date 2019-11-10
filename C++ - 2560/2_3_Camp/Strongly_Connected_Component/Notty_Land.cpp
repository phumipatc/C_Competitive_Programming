/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector< int> g[100100],inv[100100];
stack< int> st;
int component[100100],mark[100100],group;
void dfs(int now){
    mark[now]=1;
    for(int i=0;i<g[now].size();i++)
        if(mark[g[now][i]]==0)
            dfs(g[now][i]);
    st.push(now);
}
void dfs2(int now){
    mark[now]=1;
    component[now]=group;
    for(int i=0;i<inv[now].size();i++)
        if(mark[inv[now][i]]==0)
            dfs2(inv[now][i]);
}
int main(){
    int n,m,num,a,b,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        while(num--){
            scanf("%d",&a);
            g[i].push_back(a);
            inv[a].push_back(i);
        }
    }
    for(int i=1;i<=n;i++)
        if(mark[i]==0)
            dfs(i);
    memset(mark,0,sizeof mark);
    group=1;
    while(!st.empty()){
        if(mark[st.top()]==0){
            dfs2(st.top());
            group++;
        }
        st.pop();
    }
    while(k--){
        scanf("%d %d",&a,&b);
        if(component[a]==component[b])  printf("yes\n");
        else                            printf("no\n");
    }
    return 0;
}
