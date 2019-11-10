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
char a[2010][2010];
int dis[2010][2010],dir[2][4] = {{-1,1,0,0},{0,0,-1,1}};
int main(){
    int r,c,ans = 0,ni,nj,countt = 0;
    scanf("%d %d",&r,&c);
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            scanf(" %c",&a[i][j]);
            dis[i][j] = 1e9;
            if(a[i][j] == 'X')  que.push({i,j}),dis[i][j] = 0;
        }
    }
    while(!que.empty()){
        now = que.front();
        que.pop();
        for(int k=0;k<4;k++){
            ni = now.i+dir[0][k];
            nj = now.j+dir[1][k];
            if(ni<1 || nj<1 || ni>r || nj>c)    continue;
            if(a[ni][nj] == 'W')                continue;
            if(dis[ni][nj] != 1e9)              continue;
            dis[ni][nj] = dis[now.i][now.j]+1;
            if(a[ni][nj] == 'A')
                ans+=2*(dis[ni][nj]),countt++;
            a[ni][nj] = 'W';
            que.push({ni,nj});
        }
    }
    printf("%d %d\n",countt,ans);
	return 0;
}
