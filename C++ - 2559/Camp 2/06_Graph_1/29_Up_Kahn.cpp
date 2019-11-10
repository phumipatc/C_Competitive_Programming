/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int in[100100],ans[100100];
vector< int> g[100100];
priority_queue< int> heap;
int main(){
    int q,n,m,i,u,v,countt,now;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++){
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            in[v]++;
        }
        for(i=1;i<=n;i++)
            if(in[i]==0)
                heap.push(-i);
    countt=0;
    while(!heap.empty()){
        now=heap.top()*-1;
        ans[countt++]=now;
        heap.pop();
        for(i=0;i<g[now].size();i++){
            in[g[now][i] ]--;
            if(in[g[now][i] ]==0)
                heap.push(-g[now][i]);
        }
    }
    if(countt==n){
        printf("Yes ");
        for(i=0;i<n;i++)
            printf("%d ",ans[i]);
        printf("\n");
    }else
        printf("No\n");
    for(i=0;i<=n;i++)
        g[i].clear();
    memset(in,0,sizeof in);
    memset(ans,0,sizeof ans);
    }
return 0;
}
