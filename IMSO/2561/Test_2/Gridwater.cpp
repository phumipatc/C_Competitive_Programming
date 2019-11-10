
/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now,a[321000];
priority_queue< A > heap;
int n,m,p[161000],mark[161000][4],value[161000][4];
int convert(int i,int j){
    return (i*n)+j;
}
int find_root(int u){
    if(p[u] == u)   return u;
    else            return p[u] = find_root(p[u]);
}
int main(){
    int idx = 1,num,ru,rv;
    scanf("%d %d",&m,&n);
    for(int i=1;i<=n*m;i++)
        for(int j=0;j<4;j++)
            value[i][j] = 1e9;
    for(int i=1;i<(2*m);i++){
        if(i%2 == 1){
            for(int j=1;j<n;j++){
                scanf("%d",&num);
                a[idx] = {convert(i/2,j),convert(i/2,j+1),num};
                value[a[idx].u][2] = value[a[idx].v][0] = num;
                heap.push(a[idx]);
                idx++;
            }
        }else{
            for(int j=1;j<=n;j++){
                scanf("%d",&num);
                a[idx] = {convert((i/2)-1,j),convert(i/2,j),num};
                value[a[idx].u][3] = value[a[idx].v][1] = num;
                heap.push(a[idx]);
                idx++;
            }
        }
    }
    for(int i=1;i<=n*m;i++) p[i] = i;
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        ru = find_root(now.u);
        rv = find_root(now.v);
        if(ru!=rv){
            p[ru] = rv;
            if(now.v == now.u+1){
                mark[now.u][2] = mark[now.v][0] = 1;
            }else{
                mark[now.u][3] = mark[now.v][1] = 1;
            }
        }
    }
    int maxx = 1e9,minn;
    sort(a+1,a+idx);
    for(int i=1;i<idx;i++){
        now = a[i];
        if(now.v == now.u+1){
            if(!mark[now.u][2] || !mark[now.v][0])
                continue;
        }else{
            if(!mark[now.u][3] || !mark[now.v][1])
                continue;
        }
        minn = 1e9;
        if(now.u == 1){
            if(!mark[now.u][2] && value[now.u][2]>=a[i].w) minn = min(minn,value[now.u][2]);
            if(!mark[now.u][3] && value[now.u][3]>=a[i].w) minn = min(minn,value[now.u][3]);
            maxx = min(maxx,minn-a[i].w);

            continue;
        }
        if(now.u == n){
            if(!mark[now.u][0] && value[now.u][0]>=a[i].w) minn = min(minn,value[now.u][0]);
            if(!mark[now.u][3] && value[now.u][3]>=a[i].w) minn = min(minn,value[now.u][3]);
            maxx = min(maxx,minn-a[i].w);

            continue;
        }
        if(now.v == n){
            if(!mark[now.v][0] && value[now.v][0]>=a[i].w) minn = min(minn,value[now.v][0]);
            if(!mark[now.v][3] && value[now.v][3]>=a[i].w) minn = min(minn,value[now.v][3]);
            maxx = min(maxx,minn-a[i].w);

            continue;
        }
        if(now.u == n*(m-1)+1){
            if(!mark[now.u][1] && value[now.u][1]>=a[i].w) minn = min(minn,value[now.u][1]);
            if(!mark[now.u][2] && value[now.u][2]>=a[i].w) minn = min(minn,value[now.u][2]);
            maxx = min(maxx,minn-a[i].w);

            continue;
        }
        if(now.v == n*(m-1)+1){
            if(!mark[now.v][1] && value[now.v][1]>=a[i].w) minn = min(minn,value[now.v][1]);
            if(!mark[now.v][2] && value[now.v][2]>=a[i].w) minn = min(minn,value[now.v][2]);
            maxx = min(maxx,minn-a[i].w);

            continue;
        }
        if(now.v == n*m){
            if(!mark[now.v][0] && value[now.v][0]>=a[i].w) minn = min(minn,value[now.v][0]);
            if(!mark[now.v][1] && value[now.v][1]>=a[i].w) minn = min(minn,value[now.v][1]);
            maxx = min(maxx,minn-a[i].w);

            continue;
        }
        for(int j=0;j<4;j++){
            if(!mark[now.u][j] && value[now.u][j]>=a[i].w) minn = min(minn,value[now.u][j]);
            if(!mark[now.v][j] && value[now.v][j]>=a[i].w) minn = min(minn,value[now.v][j]);
        }
        maxx = min(maxx,minn-a[i].w);

    }
    printf("%d\n",maxx);
	return 0;
}
