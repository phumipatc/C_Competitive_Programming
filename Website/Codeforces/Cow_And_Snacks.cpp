/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[200010];
int mark[200010];
int n,k,man,snack;
void dfs(int now){
    mark[now] = 1;
    if(now>k)   snack++;
    else        man++;
    for(auto x:g[now]){
        if(mark[x]) continue;
        dfs(x);
    }
}
int main(){
    int u,v;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=k;i++){
        scanf("%d %d",&u,&v);
        g[i].push_back(u+k);
        g[i].push_back(v+k);
        g[u+k].push_back(i);
        g[v+k].push_back(i);
    }
    int ans = 0;
    for(int i=1;i<=k;i++){
        if(mark[i]) continue;
        dfs(i);
        ans+=(man-snack+1);
        man = snack = 0;
    }
    printf("%d\n",ans);
	return 0;
}