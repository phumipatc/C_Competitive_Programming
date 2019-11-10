/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
priority_queue<int> heap;
vector<int> g[100100];
int deg[100100],ans[100100];
int main(){
    int q,n,m,u,v,now,countt;
    scanf("%d",&q);
    while(q--){
        countt = 1;
        scanf("%d %d",&n,&m);
        while(m--){
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            deg[v]++;
        }
        for(int i=1;i<=n;i++)
            if(!deg[i])
                heap.push(-i);
        while(!heap.empty()){
            now = -heap.top();
            heap.pop();
            ans[countt++] = now;
            for(auto &x:g[now]){
                deg[x]--;
                if(!deg[x])
                    heap.push(-x);
            }
        }
        if(countt == n+1){
            printf("Yes");
            for(int i=1;i<countt;i++)
                printf(" %d",ans[i]);
            printf("\n");
        }else{
            printf("No\n");
        }
        for(int i=1;i<=n;i++)   g[i].clear();
        memset(deg,0,sizeof deg);
    }
	return 0;
}
