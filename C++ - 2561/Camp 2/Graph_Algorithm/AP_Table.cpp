/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
priority_queue<A > heap;
char a[35][35];
vector<A > g[35][35];
int dis[35][35];
int main()
{
    int q,n,x,y,w,maxx;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d %d",&n,&x,&y);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                scanf(" %c",&a[i][j]);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i-1>0){
                    if(a[i-1][j] == a[i][j])    w = x;
                    else                        w = y;
                    g[i][j].push_back({i-1,j,w});
                }
                if(j-1>0){
                    if(a[i][j-1] == a[i][j])    w = x;
                    else                        w = y;
                    g[i][j].push_back({i,j-1,w});
                }
                if(i+1<=n){
                    if(a[i+1][j] == a[i][j])    w = x;
                    else                        w = y;
                    g[i][j].push_back({i+1,j,w});
                }
                if(j+1<=n){
                    if(a[i][j+1] == a[i][j])    w = x;
                    else                        w = y;
                    g[i][j].push_back({i,j+1,w});
                }
            }
        }
        maxx = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++)
                    for(int l=1;l<=n;l++)
                        dis[k][l] = 1e9;
                dis[i][j] = 0;
                heap.push({i,j,0});
                while(!heap.empty()){
                    now = heap.top();
                    heap.pop();
                    for(auto x:g[now.i][now.j]){
                        if(dis[x.i][x.j]>dis[now.i][now.j]+x.w){
                            dis[x.i][x.j] = dis[now.i][now.j]+x.w;
                            heap.push({x.i,x.j,dis[x.i][x.j]});
                        }
                    }
                }
                for(int k=1;k<=n;k++)
                    for(int l=1;l<=n;l++)
                        maxx = max(maxx,dis[k][l]);
            }
        }
        printf("%d\n",maxx);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                g[i][j].clear();
    }
    return 0;
}
