/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char a[32][32];
queue<pair<int ,int > > que;
pair<int ,int > now;
int dir[2][4] = {{-1,1,0,0},{0,0,1,-1}};
int main(){
    int n,m,sti,stj;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf(" %c",&a[i][j]);
            if(a[i][j] == 'A')  sti = i,stj = j;
        }
    }
    que.push({sti,stj});
    int ch = 0,ans = 0;
    while(!que.empty()){
        now = que.front();
        que.pop();
        for(int k=0;k<4;k++){
            int ni = now.first+dir[0][k],nj = now.second+dir[1][k];
            if(ni<1 || nj<1 || ni>n || nj>m)    continue;
            if(a[ni][nj] == '#')                continue;
            que.push({ni,nj});
            if(a[ni][nj] == 'W')    ch = 1;
            if(a[ni][nj] == '*')    ans++;
            a[ni][nj] = '#';
        }
    }
    if(!ch){
        printf("%d\n",ans);
        return 0;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j] == 'W')
                que.push({i,j}),a[i][j] = '#';
    while(!que.empty()){
        now = que.front();
        que.pop();
        for(int k=0;k<4;k++){
            int ni = now.first+dir[0][k],nj = now.second+dir[1][k];
            if(ni<1 || nj<1 || ni>n || nj>m)    continue;
            if(a[ni][nj] == '#')                continue;
            que.push({ni,nj});
            if(a[ni][nj] == '*')    ans++;
            a[ni][nj] = '#';
        }
    }
    printf("%d\n",ans);
    return 0;
}