/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[100005],inv[100005];
stack<int > st;
int mark[100005],component[100005],group;
void dfs(int now){
    mark[now] = 1;
    for(int i=0;i<g[now].size();i++)
        if(!mark[g[now][i]])
            dfs(g[now][i]);
    st.push(now);
}
void dfs2(int now){
    mark[now] = 1;
    component[now] = group;
    for(int i=0;i<inv[now].size();i++)
        if(!mark[inv[now][i]])
            dfs2(inv[now][i]);
}
int main(){
    int n,m,k,u,v;
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        cin >> u;
        while(u--){
            cin >> v;
            g[i].push_back(v);
            inv[v].push_back(i);
        }
    }
    for(int i=1;i<=n;i++)
        if(!mark[i])
            dfs(i);
    memset(mark,0,sizeof mark);
    while(!st.empty()){
        if(!mark[st.top()]){
            group++;
            dfs2(st.top());
        }
        st.pop();
    }
    int a,b;
    while(k--){
        cin >> a >> b;
        if(component[a] == component[b])    cout << "yes" << endl;
        else                                cout << "no" << endl;
    }
    return 0;
}
