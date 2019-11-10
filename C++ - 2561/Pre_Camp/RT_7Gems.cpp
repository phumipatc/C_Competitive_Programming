#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,w,gem;
};
A now;
queue <A> que;
int dis[6][128][205][205],g[205][205];
char a[205][205];
int countt,di[]={-1,1,0,0,0},dj[]={0,0,-1,1,0};
int main(){
    int n,m,i,j,ni,nj,nw,k,val;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf(" %c",&a[i][j]);
            if(a[i][j] == 'S')
                que.push({i,j,0,0}),dis[0][0][i][j] = 1;
            if(a[i][j] == 'G')
                g[i][j] = 1<<countt++;
        }
    }
    while(!que.empty()){
        now = que.front();
        que.pop();
        if(now.gem == (1<<7)-1){
            printf("%d",now.w);
            return 0;
        }
        for(k=0;k<5;k++)
        {
            ni = now.i+di[k];
            nj = now.j+dj[k];
            nw = (now.w+1)%6;
            if(ni<0 || nj<0 || ni>=n || nj>=m)
                continue ;
            if(a[ni][nj]=='#')
                continue ;
            if(isdigit(a[ni][nj])){
                if(a[ni][nj]-'1'==nw);
                else if(a[ni][nj]-'0'<=__builtin_popcount(now.gem));
                else    continue ;
            }
            if(dis[(now.w+1)%6][now.gem|g[ni][nj]][ni][nj]) continue ;
            dis[(now.w+1)%6][now.gem|g[ni][nj]][ni][nj] = 1;
            que.push({ni,nj,now.w+1,now.gem|g[ni][nj]});
        }
    }
    printf("-1\n");
    return 0;
}
