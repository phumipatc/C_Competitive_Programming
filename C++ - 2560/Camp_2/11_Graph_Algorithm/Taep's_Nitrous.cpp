/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w,k;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
priority_queue< A> heap; // Dijkstra
vector< A> g[5100];
int dis[5100][110];
int main()
{
    A temp;
    int n,m,k,s,i,j,nowu,noww,nowk;
    scanf("%d %d %d",&n,&m,&k);
    while(m--){
        scanf("%d %d %d",&s,&temp.v,&temp.w);
        temp.k=0;
        g[s].push_back(temp);
        swap(s,temp.v);
        g[s].push_back(temp);
    }
    for(i=1;i<=n;i++)
        for(j=0;j<=k;j++)
            dis[i][j]=1e9;
    dis[1][0]=0;
    temp.v=1,temp.w=0,temp.k=0;
    heap.push(temp);
    while(!heap.empty()){
        temp=heap.top();
        heap.pop();
        nowu=temp.v,noww=temp.w,nowk=temp.k;
        for(i=0;i<g[nowu].size();i++){
//            if(dis[n][k]!=1e9)
//                break;
            if(noww+g[nowu][i].w<dis[g[nowu][i].v][nowk]){
                dis[g[nowu][i].v][nowk]=noww+g[nowu][i].w;
                temp.v=g[nowu][i].v,temp.w=noww+g[nowu][i].w;
                temp.k=nowk;
                heap.push(temp);
            }
            if(noww+g[nowu][i].w/2<dis[g[nowu][i].v][nowk+1]){
                dis[g[nowu][i].v][nowk+1]=noww+g[nowu][i].w/2;
                temp.v=g[nowu][i].v,temp.w=noww+g[nowu][i].w/2;
                temp.k=nowk+1;
                heap.push(temp);
            }
        }
    }
    printf("%d\n",dis[n][0]);
    int minn=1e9;
    for(i=1;i<=k;i++)
        minn=min(minn,dis[n][i]);
    printf("%d\n%d\n",minn,dis[n][0]-minn);
    return 0;
}
/*
6 8 1
1 2 4
1 4 2
2 3 4
2 4 6
3 6 6
4 3 12
4 5 10
5 6 4
*/
