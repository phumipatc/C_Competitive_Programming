/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MAX 100100
using namespace std;
vector< int> g[MAX];
stack< int> st;
int low[MAX],idx[MAX],onstack[MAX],comp[MAX];
int group=1,countt=1;
void dfs(int now){
    low[now]=idx[now]=group++;
    st.push(now);
    onstack[now]=1;
    for(auto &i: g[now]){
        if(idx[i]==0){
            dfs(i);
            low[now]=min(low[now],low[i]);
        }else if(onstack[i])
            low[now]=min(low[now],idx[i]);
    }
    if(idx[now]==low[now]){
        while(st.top()!=now){
            onstack[st.top()]=0;
            comp[st.top()]=countt;
            st.pop();
        }
        st.pop();
        onstack[now]=0;
        comp[now]=countt++;
    }
}
int main(){
    int n,m,k,j,num;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&j);
        while(j--){
            scanf("%d",&num);
            g[i].push_back(num);
        }
    }
    for(int i=1;i<=n;i++)
        if(!idx[i])
            dfs(i);
    int u,v;
    while(k--){
        scanf("%d %d",&u,&v);
        printf((comp[u]==comp[v])?"yes\n":"no\n");
    }
    return 0;
}
