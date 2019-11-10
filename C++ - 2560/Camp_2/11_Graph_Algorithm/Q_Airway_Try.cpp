/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w,type;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
vector< A> g[1100];
priority_queue< A> heap;
int dis[1100];
int main()
{
    A temp,temp2;
    int v,e,a,i,st,en,dissappear;
    scanf("%d %d %d %d",&v,&e,&st,&en);
    for(i=1;i<=v;i++)   dis[i]=1e9;
    dis[st]=0;
    scanf("%d %d %d %d",&a,&temp.v,&temp.w,&dissappear);
    temp.type=1,temp.u=a;
    g[a].push_back(temp);
    for(i=0;i<e;i++){
        scanf("%d %d %d",&a,&temp.v,&temp.w);
        temp.type=2,temp.u=a;
        g[a].push_back(temp);
    }
    for(i=0;i<g[st].size();i++){
        temp.u=st;
        temp.v=g[st][i].v;
        temp.w=g[st][i].w;
        temp.type=g[st][i].type;
        heap.push(temp);
    }
    while(!heap.empty()){
        temp=heap.top();
        heap.pop();
//        printf("start: %d\nend: %d\nweight: %d\ntype: %d\nfirst dis: %d\n\n",temp.u,temp.v,temp.w,temp.type,dis[temp.u]);
        if(temp.type==2 && dis[temp.u]+temp.w<dis[temp.v]){
            dis[temp.v]=dis[temp.u]+temp.w;
            for(i=0;i<g[temp.v].size();i++){
                temp2.u=g[temp.v][i].u;
                temp2.w=g[temp.v][i].w;
                temp2.type=g[temp.v][i].type;
                temp2.v=g[temp.v][i].v;
                heap.push(temp2);
            }
        }else if(temp.type==1 && dis[temp.u]<=dissappear){
            if(dis[temp.u]+temp.w<dis[temp.v]){
                dis[temp.v]=dis[temp.u]+temp.w;
                for(i=0;i<g[temp.v].size();i++){
                    temp2.u=g[temp.v][i].u;
                    temp2.w=g[temp.v][i].w;
                    temp2.type=g[temp.v][i].type;
                    temp2.v=g[temp.v][i].v;
                    heap.push(temp2);
                }
            }
        }
    }
    printf("%d\n",dis[en]);
    return 0;
}
/*
4 4
0 3
1 3 -10 10
0 1 5
0 3 10
1 3 3
2 3 5
*/
