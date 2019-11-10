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
int dis[2010][2010],dir[2][4] = {{-1,1,0,0},{0,0,-1,1}};
char a[2010][2010];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf(" %s",a[i]+1);
        for(int j=1;j<=m;j++){
            dis[i][j] = 1e9;
            if(a[i][j]!='X')    continue;
            dis[i][j] = 0;
            que.push({i,j});
        }
    }
    int ans1 = 0,ans2 = 0;
    while(!que.empty()){
        now = que.front();
        que.pop();
        if(a[now.i][now.j] == 'A')  ans1++,ans2+=2*dis[now.i][now.j];
        for(int k=0;k<4;k++){
            int ni = now.i+dir[0][k],nj = now.j+dir[1][k];
            if(ni<1 || nj<1 || ni>n || nj>m)        continue;
            if(dis[ni][nj]<=dis[now.i][now.j]+1)    continue;
            if(a[ni][nj] == 'W')                    continue;
            dis[ni][nj] = dis[now.i][now.j]+1;
            que.push({ni,nj});
        }
    }
    printf("%d %d\n",ans1,ans2);
	return 0;
}
