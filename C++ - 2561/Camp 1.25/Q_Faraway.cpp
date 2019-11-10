/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w;
};
A now;
vector< A> g[100100];
queue< A> que;
int mark[100100];
int main(){
    int q,n,m,u,v,w,ans;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        for(int i=1;i<n;i++){
            scanf("%d %d %d",&u,&v,&w);
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        que.push({1,0});
        mark[1] = 1;
        ans = -1;
        while(!que.empty()){
            now = que.front();
            que.pop();
            if(now.w>=m)
                ans = max(ans,now.w);
            for(auto &x:g[now.v]){
                if(mark[x.v])   continue;
                mark[x.v] = 1;
                que.push({x.v,now.w+x.w});
            }
        }
        printf("%d\n",ans);
        for(int i=1;i<=n;i++)
            g[i].clear();
        memset(mark,0,sizeof mark);
    }
	return 0;
}
