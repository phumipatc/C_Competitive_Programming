/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,p;
};
A now;
queue<A > que;
vector<int > g[10010];
int mark[10010];
int main(){
    int k,n,m,u,v;
    scanf("%d %d %d",&k,&n,&m);
    while(m--){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
    }
    que.push({1,0});
    mark[1] = 1;
    int ans = 1;
    while(!que.empty()){
        now = que.front();
        que.pop();
        mark[now.u] = 1;
        ans = max(ans,now.u);
        if(now.p == k)  continue;
        for(auto x:g[now.u]){
            if(mark[x]) continue;
            que.push({x,now.p+1});
        }
    }
    printf("%d\n",ans);
	return 0;
}
