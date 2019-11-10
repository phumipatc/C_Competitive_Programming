/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char table[110][110];
struct A{
    int i,j;
};
struct B{
    int i,j,dis,key;
};
struct C{
    int y,dis;
};
struct D{
    int i,dis,key;
    bool operator <(const D & o)const{
        return dis > o.dis;
    }
};
A a[40];
queue < B> q;
vector < C> g[40];
priority_queue < D> heap;
int pos[110][110],dist[40][40],mark[110][110],dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int dis[40][1<<16];
int main()
{

    int n,i,j,sti,stj,eni,enj,k,countt=1,w,l,key,nowkey;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf(" %c",&table[i][j]);
    scanf("%d %d %d %d %d",&sti,&stj,&eni,&enj,&k);
    a[1].i = sti;
    a[1].j = stj;
    pos[sti][stj] = 1;
    a[2].i = eni;
    a[2].j = enj;
    pos[eni][enj] = 2;
    for(i=1;i<=k;i++){
        scanf("%d %d %d %d",&sti,&stj,&eni,&enj);
        a[i+2].i = sti;
        a[i+2].j = stj;
        pos[sti][stj] = i+2;
        a[i+2+k].i = eni;
        a[i+2+k].j = enj;
        pos[eni][enj] = i+k+2;
    }
    for(i=1;i<=k+k+2;i++){
        for(j=2;j<=k+k+2;j++){
            dist[i][j]=1e9;
            mark[a[i].i][a[i].j] = countt;
            q.push({a[i].i,a[i].j,0,0});
            while(!q.empty()){
                sti = q.front().i;
                stj = q.front().j;
                w = q.front().dis;
                q.pop();
                if(pos[sti][stj]==j){
                    dist[i][j] = w;
                    break;
                }
                for(l=0;l<4;l++){
                    eni = sti + dir[l][0];
                    enj = stj + dir[l][1];
                    if(eni < 1 || enj < 1 || eni > n || enj > n || table[eni][enj]=='#')    continue ;
                    if(pos[sti][stj] != i && pos[sti][stj]>=k+3)                            continue;
                    if(mark[eni][enj] != countt){
                        mark[eni][enj] = countt;
                        q.push({eni,enj,w+1,0});
                    }
                }
            }
            while(!q.empty())
                q.pop();
            countt++;
            if(dist[i][j] != 1e9){
                g[i].push_back({j,dist[i][j]});
                g[j].push_back({i,dist[i][j]});
            }
        }
    }
    for(i=1;i<=k+k+2;i++)
        for(j=0;j<=1<<k;j++)
            dis[i][j] = 1e9;
    dis[1][0] = 0;
    heap.push({1,0,0});
    while(!heap.empty()){
        sti = heap.top().i;
        w = heap.top().dis;
        key = heap.top().key;
        heap.pop();
        if(sti == 2){
            printf("%d\n",w);
            return 0;
        }
        for(i=0;i<g[sti].size();i++){
            nowkey = key;
            if(g[sti][i].y > 2 && g[sti][i].y <= k+2)
                nowkey |= (1<<(g[sti][i].y - 3));
            if(g[sti][i].y >= k+3 && ((nowkey & (1<<(g[sti][i].y - k - 3))) != 0) && w + g[sti][i].dis < dis[g[sti][i].y][nowkey]){
                dis[g[sti][i].y][nowkey] = w + g[sti][i].dis;
                heap.push({g[sti][i].y,dis[g[sti][i].y][nowkey],nowkey});
            }else if(g[sti][i].y < k+3 && w + g[sti][i].dis < dis[g[sti][i].y][nowkey]){
                dis[g[sti][i].y][nowkey] = w + g[sti][i].dis;
                heap.push({g[sti][i].y,dis[g[sti][i].y][nowkey],nowkey});
            }
        }
    }
    printf("-1\n");
    return 0;
}
/*
5
..#..
...#.
...#.
...#.
.....
1 1 1 5 2
1 2 4 5
4 1 3 5
*/
