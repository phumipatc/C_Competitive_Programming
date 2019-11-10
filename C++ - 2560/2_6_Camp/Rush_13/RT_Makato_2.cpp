/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[100005];
int a[100005],mark[100005],XOR[100005],sum[100005],lv[100005];
void dfs(int now,int level){
    mark[now] = 1;
    lv[now] = level;
    XOR[now] = a[now];
    for(int i=0;i<g[now].size();i++){
        if(!mark[g[now][i]]){
            dfs(g[now][i],level+1);
            XOR[now]^=XOR[g[now][i]];
        }
    }
}
int main(){
    int n,u,v,minn = 1e9,sum;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<n;i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,1);
    for(int i=1;i<=n;i++){
        sum = XOR[1]^XOR[i];
        for(int j=0;j<g[i].size();j++)
            sum+=XOR[g[i][j]];
        minn = min(minn,sum);
    }
    cout << minn << endl;
    return 0;
}
