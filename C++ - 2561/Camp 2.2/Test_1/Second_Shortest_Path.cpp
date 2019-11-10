/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int pos,dis;
    bool operator < (const A&o)const{
        return dis>o.dis;
    }
};
A now;
priority_queue< A> heap;
vector< A> g[10100];
int dis[10100],mark[10100];
int main(){
    int n,m,st,en,i,u,v,d,ch=-1;
    scanf("%d %d %d %d",&n,&m,&st,&en);
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&d);
        g[u].push_back({v,d});
    }
    memset(dis,-1,sizeof dis);
    heap.push({st,0});
    while(!heap.empty()){
        now = heap.top();
//        printf("%d\n",now.pos);
        heap.pop();
        if(mark[now.pos]>=2 || now.dis == dis[now.pos])  continue;
        mark[now.pos]++;
        dis[now.pos] = now.dis;
        if(now.pos == en && ch!=-1){
            if(now.dis>ch){
                printf("%d\n",now.dis);
                return 0;
            }
        }else if(now.pos == en)
            ch = now.dis;
        for(auto x:g[now.pos])
            heap.push({x.pos,now.dis+x.dis});
    }
    return 0;
}
/*
3 3
1 3
1 2 1
1 3 3
2 3 1
*/
