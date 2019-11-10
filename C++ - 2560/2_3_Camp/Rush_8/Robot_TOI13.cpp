/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,dis;
};
queue< A> que;
char a[2100][2100];
int mark[2100][2100];
int dir[2][4]={{1,-1,0,0},{0,0,1,-1}};
int main(){
    int n,m,countt=0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf(" %c",&a[i][j]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]=='X')    que.push({i,j,0}),mark[i][j]=1;
            if(a[i][j]=='A')    countt++;
        }
    }
    int dis=0,temp=countt;
    while(!que.empty()){
        A now=que.front();
        que.pop();
        if(a[now.i][now.j]=='A'){
            a[now.i][now.j]='E';
            dis+=now.dis*2;
            temp--;
        }
        if(temp==0) break;
        for(int k=0;k<4;k++){
            int nexti=now.i+dir[0][k];
            int nextj=now.j+dir[1][k];
            if(nexti<1 || nexti>n || nextj<1 || nextj>m)        continue;
            if(mark[nexti][nextj]==1 || a[nexti][nextj]=='W')   continue;
            mark[nexti][nextj]=1;
            que.push({nexti,nextj,now.dis+1});
        }
    }
    printf("%d %d\n",countt-temp,dis);
    return 0;
}
