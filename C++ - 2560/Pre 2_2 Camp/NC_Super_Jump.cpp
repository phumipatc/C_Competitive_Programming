/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,k;
    double w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
vector< A> g[10100];
priority_queue< A> heap;
double dis[5][10100];
int mark[5][10100];
A a;
int main(){
    int n,m,i,j,u,v,k;
    double w;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d %lf",&u,&a.v,&a.w);
        a.k=0;
        g[u].push_back(a);
        swap(a.v,u);
        g[u].push_back(a);
    }
    for(i=0;i<2;i++)
        for(j=0;j<n;j++)
            dis[i][j]=1e9;
    dis[0][0]=0;
    a.v=0,a.w=0,a.k=0;
    heap.push(a);
    while(!heap.empty()){
        u=heap.top().v,w=heap.top().w,k=heap.top().k;
//        printf("%d %.2lf %d\n",u,w,k);
        heap.pop();
        for(i=0;i<g[u].size();i++){
            if(w+g[u][i].w<dis[k][g[u][i].v]){
                dis[k][g[u][i].v]=w+g[u][i].w;
                a.v=g[u][i].v,a.w=w+g[u][i].w,a.k=k;
                heap.push(a);
            }
            if(w+0.14<dis[k+1][g[u][i].v]){
                dis[k+1][g[u][i].v]=w+0.14;
                a.v=g[u][i].v,a.w=w+0.14,a.k=k+1;
                heap.push(a);
            }
        }
    }
    printf("%.2lf\n",min(dis[0][n-1],dis[1][n-1]));
    return 0;
}
