/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[1010];
int mark[1010];
void dfs(int now){
    if(mark[now])   return ;
    mark[now] = 1;
    for(auto &x:g[now]){
        dfs(x);
    }
}
int main(){
    int n,m,q,u,v;
    scanf("%d %d %d",&n,&m,&q);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
    }
    while(q--){
        scanf("%d %d",&u,&v);
        memset(mark,0,sizeof mark);
        dfs(u);
        if(mark[v]) printf("Yes\n");
        else        printf("No\n");
    }
	return 0;
}
