/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[410];
int mark[410],comp[410];
int countt = 1;
void dfs(int now){
    comp[countt]++;
    mark[now] = countt;
    for(auto x:g[now]){
        if(mark[x]) continue;
        dfs(x);
    }
}
int main(){
    int q,u,v,n,m,u,v,ans,minn,maxx;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n,&m);
        for(int i=1;i<=n;i++)
            g[i].clear();
        while(m--){
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        memset(mark,0,sizeof mark);
        minn = 1e9,maxx = 0;
        for(int i=1;i<=n;i++){
            if(mark[i]) continue;
            dfs(i);
            maxx = max(maxx,comp[countt]);
            minn = min(minn,comp[countt]);
            countt++;
        }
        if(countt>2)
            printf("-1\n");
        else if(countt == 2)
            printf("%d\n",maxx-minn);
        else{
            
        }
    }
	return 0;
}
