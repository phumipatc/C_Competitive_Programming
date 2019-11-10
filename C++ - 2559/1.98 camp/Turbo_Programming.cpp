/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
vector< PII> g[1010];
int d[1010],mark[1010],n,m,q;
priority_queue< PII> h;
int main(){
    int i,s,e,w,dis,u;
    for(i=1;i<=1000;i++)
        d[i]=1<<30,mark[i]=0;
    d[1]=0;
    scanf("%d %d %d",&n,&m,&q);
    for(i=0;i<m;i++){
        scanf("%d %d %d",&s,&e,&w);
        g[s].push_back(PII(e,w));
    }
    h.push(PII(0,1));
    while(!h.empty()){
        dis=h.top().first*-1;
        u=h.top().second;
        h.pop();
        if(mark[u]==0){
            mark[u]=1;
            d[u]=dis;
            for(i=0;i<g[u].size();i++){
                if(mark[g[u][i].first]==0){
                    h.push(PII((dis+g[u][i].second)*-1,g[u][i].first));
                }
            }
        }
    }
    while(q--){
        scanf("%d",&u);
        if(d[u]==1<<30)
            printf("-1\n");
        else
            printf("%d\n",d[u]);
    }
return 0;
}
