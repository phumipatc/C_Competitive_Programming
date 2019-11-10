/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[1010];
int mark[1010],doing[1010];
void dfs(int now){
    doing[now] = 1;
    mark[now] = 0;
    for(auto x:g[now]){
        if(mark[x] == -1)   dfs(x);
        if(doing[x] || mark[x]){
            mark[now] = 1;
            doing[now] = 0;
            return ;
        }
    }
    doing[now] = 0;
}
int main(){
    int n,m,u,v;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
    }
    int q,temp,num,ch;
    scanf("%d",&q);
    while(q--){
        memset(mark,-1,sizeof mark);
        ch = 0;
        scanf("%d",&temp);
        while(temp--){
            scanf("%d",&num);
            mark[num] = 0;
        }
        for(int i=1;i<=n;i++){
            if(mark[i] == -1)   dfs(i);
            if(mark[i])         printf("%d ",i),ch = 1;
        }
        if(!ch) printf("-1");
        printf("\n");
    }
	return 0;
}
