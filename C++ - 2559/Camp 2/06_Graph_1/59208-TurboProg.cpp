/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w;
};
struct B{
    int v,w;
    bool operator < (const B&o) const{
        if(w<o.w)
            return false;
        else
            return true;
    }
};
vector< A> g[1010];
int dist[1010],mark[1010];
priority_queue< B> heap;
int main(){
    A temp;
    B tem;
    int n,m,q,i,s,e,w,nowu,noww;
    scanf("%d %d %d",&n,&m,&q);
    for(i=0;i<m;i++){
        scanf("%d %d %d",&s,&e,&w);
        temp.v=e;
        temp.w=w;
        g[s].push_back(temp);
    }
    for(i=1;i<=n;i++)
        dist[i]=1<<25;
    dist[1]=0;
    tem.v=1;
    tem.w=0;
    heap.push(tem);
    while(!heap.empty()){
        nowu=heap.top().v;
        noww=heap.top().w;
        heap.pop();
        if(mark[nowu]==0){
            mark[nowu]=1;
            dist[nowu]=noww;
            for(i=0;i<g[nowu].size();i++){
                if(mark[g[nowu][i].v]==0 && dist[nowu]+g[nowu][i].w<dist[g[nowu][i].v]){
                    tem.v=g[nowu][i].v;
                    tem.w=dist[nowu]+g[nowu][i].w;
                    heap.push(tem);
                }
            }
        }
    }
    for(i=0;i<q;i++){
        scanf("%d",&s);
        if(dist[s]==1<<25)
            printf("-1\n");
        else
            printf("%d\n",dist[s]);
    }
return 0;
}
