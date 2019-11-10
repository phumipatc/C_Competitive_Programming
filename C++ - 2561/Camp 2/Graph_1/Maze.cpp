/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j;
};
A now;
queue<A > que;
int a[155][155],dis[155][155][2],dir[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int main(){
    int m,n,sti,stj,eni,enj,ni,nj,ans = 1e9,countt = 0;
    scanf("%d %d %d %d %d %d",&n,&m,&sti,&stj,&eni,&enj);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    que.push({sti,stj});
    dis[sti][stj][0] = 1;
    while(!que.empty()){
        now = que.front();
        que.pop();
        for(int k=0;k<4;k++){
            ni = now.i+dir[0][k];
            nj = now.j+dir[1][k];
            if(ni<1 || nj<1 || ni>n || nj>m)    continue;
            if(dis[ni][nj][0])                  continue;
            if(a[ni][nj] == 0)                  continue;
            dis[ni][nj][0] = dis[now.i][now.j][0]+1;
            que.push({ni,nj});
        }
    }
    que.push({eni,enj});
    dis[eni][enj][1] = 1;
    while(!que.empty()){
        now = que.front();
        que.pop();
        for(int k=0;k<4;k++){
            ni = now.i+dir[0][k];
            nj = now.j+dir[1][k];
            if(ni<1 || nj<1 || ni>n || nj>m)    continue;
            if(dis[ni][nj][1])                  continue;
            if(a[ni][nj] == 0)                  continue;
            dis[ni][nj][1] = dis[now.i][now.j][1]+1;
            que.push({ni,nj});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]) continue;
            int fir = 1;
            for(int k=0;k<4;k++){
                for(int l=0;l<4;l++){
                    if(k == l)  continue;
                    if(dis[i+dir[0][k]][j+dir[1][k]][0] && dis[i+dir[0][l]][j+dir[1][l]][1]){
                        if(fir) countt++,fir = 0;
                        ans = min(ans,dis[i+dir[0][k]][j+dir[1][k]][0]+dis[i+dir[0][l]][j+dir[1][l]][1]+1);
                    }
                }
            }
        }
    }
    printf("%d\n%d\n",countt,ans);
	return 0;
}
