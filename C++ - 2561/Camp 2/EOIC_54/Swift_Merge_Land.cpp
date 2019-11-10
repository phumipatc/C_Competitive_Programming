/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,w;
};
A now;
queue<A > que;
char a[52][52];
int dir[2][4] = {{-1,1,0,0},{0,0,1,-1}},mark[52][52];
void dfs(int i,int j,char num){
    a[i][j] = num+'1';
    for(int k=0;k<4;k++){
        int ni = i+dir[0][k],nj = j+dir[1][k];
        if(a[ni][nj] != 'X')    continue;
        dfs(ni,nj,num);
    }
}
int main(){
    int r,c,num = 0;
    scanf("%d %d",&r,&c);
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            scanf(" %c",&a[i][j]);
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(a[i][j]!='X')    continue;
            dfs(i,j,num);
            num++;
        }
    }
    int ans = 1e9;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(a[i][j]!='.')    continue;
            que.push({i,j,0});
            int dis = 1e9,dis2 = 1e9;
            memset(mark,0,sizeof mark);
            mark[i][j] = 1;
            while(!que.empty()){
                now = que.front();
                que.pop();
                for(int k=0;k<4;k++){
                    int ni = now.i+dir[0][k],nj = now.j+dir[1][k];
                    if(ni<1 || nj<1 || ni>r || nj>c)    continue;
                    if(mark[ni][nj])                    continue;
                    if(a[ni][nj] == '1'){
                        dis = min(dis,now.w+1);
                    }else if(a[ni][nj] == '2'){
                        dis2 = min(dis2,now.w+1);
                    }else{
                        mark[ni][nj] = 1;
                        que.push({ni,nj,now.w+1});
                    }
                }
            }
            ans = min(ans,dis+dis2-1);
        }
    }
    printf("%d\n",ans);
	return 0;
}
