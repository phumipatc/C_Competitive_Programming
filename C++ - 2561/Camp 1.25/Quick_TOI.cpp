/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[1010];
int mark[1010],ans[1010];
void dfs(int now,int state){
    if(state<0) return ;
    ans[now] = 1;
    for(auto &x:g[now]){
        dfs(x,state-1);
    }
}
int main(){
    int n,u,v;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&u,&v);
        mark[u] = mark[v] = 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    while(1){
        scanf("%d %d",&u,&v);
        if(u == 0 && v == 0)    break;
        dfs(u,v);
        u = 0;
        for(int i=1;i<=1000;i++)
            if(mark[i] && !ans[i])
                u++;
        printf("%d\n",u);
        memset(ans,0,sizeof ans);
    }
	return 0;
}
/*
16
10 15
15 20
20 25
10 30
30 47
47 50
25 45
45 65
15 35
35 55
20 40
50 55
35 40
55 60
40 60
60 65
*/
