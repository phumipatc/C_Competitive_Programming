/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[1010];
int w[1010],mark[1010],deg[1010];
int dfs(int now){
    if(mark[now])   return 0;
    mark[now] = 1;
    int sum = w[now];
    for(auto &x:g[now]){
        sum+=dfs(x);
    }
    return sum;
}
int main(){
    int n,m,u,v,ans = -1e9,temp,now;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        deg[v]++;
    }
    for(int i=1;i<=n;i++){
        if(deg[i])  continue;
        temp = dfs(i);
        memset(mark,0,sizeof mark);
        if(ans<temp){
            ans = temp;
            now = i;
        }
    }
    printf("%d %d\n",now,ans);
	return 0;
}
