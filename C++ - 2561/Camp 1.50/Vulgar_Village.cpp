/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[50100];
int c[50100],countt[3];
void dfs(int now,int col){
    if(c[now])  return ;
    c[now] = col;
    countt[col]++;
    for(auto &x:g[now])
        dfs(x,3-col);
}
int main(){
    int n,m,u,v,ans = 0;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(c[i])    continue;
        countt[1] = countt[2] = 0;
        dfs(i,1);
        if(countt[1]>countt[2]) swap(countt[1],countt[2]);
        ans+=(countt[1]*3)+countt[2];
    }
    printf("%d\n",ans);
	return 0;
}
