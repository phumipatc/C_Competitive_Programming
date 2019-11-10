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
A now;
queue< A> que;
int mark[2005][2005],dir[2][4]={{1,-1,0,0},{0,0,1,-1}};
char a[2010][2010];
int main(){
    int n,m,all = 0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf(" %s",a[i]+1);
        for(int j=1;j<=m;j++){
            if(a[i][j] == 'X')
                que.push({i,j,0}),mark[i][j] = 1;
            else if(a[i][j] == 'A')
                all++;
        }
    }
    int ans = 0,noww = all;
    while(!que.empty()){
        now = que.front();
        que.pop();
        if(a[now.i][now.j] == 'A'){
            a[now.i][now.j] = 'E';
            ans+=now.dis*2;
            noww--;
        }
        if(!noww)   break;
        for(int k=0;k<4;k++){
            int nexti = now.i+dir[0][k];
            int nextj = now.j+dir[1][k];
            if(nexti<1 || nexti>n || nextj<1 || nextj>m)        continue;
            if(mark[nexti][nextj]==1 || a[nexti][nextj]=='W')   continue;
            mark[nexti][nextj] = 1;
            que.push({nexti,nextj,now.dis+1});
        }
    }
    printf("%d %d\n",all-noww,ans);
    return 0;
}
