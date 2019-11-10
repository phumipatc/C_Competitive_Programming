/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long i,j,c,maxx;
};
queue < A> que;
char a[600][600];
long long dis[600][600][50],dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int main()
{
    long long n,m,i,j,si,sj,ei,ej,nowi,nowj,nowc,nowmaxx,nexti,nextj,ans=1e9,k;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf(" %c",&a[i][j]);
            if(a[i][j] == 'S')  si = i,sj = j;
            if(a[i][j] == 'E')  ei = i,ej = j;
        }
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            for(k=0;k<=20;k++)
                dis[i][j][k] = 1e9;
    que.push({si,sj,0,0});
    dis[si][sj][0] = 0;
    while(!que.empty()){
        nowi = que.front().i;
        nowj = que.front().j;
        nowc = que.front().c;
        nowmaxx = que.front().maxx;
        que.pop();
        for(i=0;i<4;i++){
            nexti = nowi + dir[i][0];
            nextj = nowj + dir[i][1];
            if(nexti < 1 || nextj < 1 || nexti > n || nextj > m || a[nexti][nextj] == '#')
                continue ;
            if(a[nexti][nextj] == 'J' && (nowmaxx & 1<<0) != 0 && nowc + 1 < dis[nexti][nextj][nowmaxx]){
                dis[nexti][nextj][nowmaxx] = nowc+1;
                que.push({nexti,nextj,nowc+1,nowmaxx});
            }
            if(a[nexti][nextj] == 'B' && (nowmaxx & 1<<1) != 0 && nowc + 1 < dis[nexti][nextj][nowmaxx]){
                dis[nexti][nextj][nowmaxx] = nowc+1;
                que.push({nexti,nextj,nowc+1,nowmaxx});
            }
            if(a[nexti][nextj] == 'P' && (nowmaxx & 1<<2) != 0 && nowc + 1 < dis[nexti][nextj][nowmaxx]){
                dis[nexti][nextj][nowmaxx] = nowc+1;
                que.push({nexti,nextj,nowc+1,nowmaxx});
            }
            if(a[nexti][nextj] == 'j' && nowc + 1 < dis[nexti][nextj][nowmaxx]){
                dis[nexti][nextj][nowmaxx] = nowc+1;
                dis[nexti][nextj][nowmaxx|1<<0] = nowc+1;
                que.push({nexti,nextj,nowc+1,nowmaxx|1<<0});
            }
            if(a[nexti][nextj] == 'b' && nowc + 1 < dis[nexti][nextj][nowmaxx]){
                dis[nexti][nextj][nowmaxx] = nowc+1;
                dis[nexti][nextj][nowmaxx|1<<1] = nowc+1;
                que.push({nexti,nextj,nowc+1,nowmaxx|1<<1});
            }
            if(a[nexti][nextj] == 'p' && nowc + 1 < dis[nexti][nextj][nowmaxx]){
                dis[nexti][nextj][nowmaxx] = nowc+1;
                dis[nexti][nextj][nowmaxx|1<<2] = nowc+1;
                que.push({nexti,nextj,nowc+1,nowmaxx|1<<2});
            }
            if((a[nexti][nextj] == '.' || a[nexti][nextj] == 'E' || a[nexti][nextj] == 'S') && nowc + 1 < dis[nexti][nextj][nowmaxx]){
                dis[nexti][nextj][nowmaxx] = nowc+1;
                que.push({nexti,nextj,nowc+1,nowmaxx});
            }
        }
    }
    for(k=0;k<=20;k++)
        ans = min(ans,dis[ei][ej][k]);
    if(ans == 1e9)  printf("-1\n");
    else            printf("%d\n",ans);
    return 0;
}
/*

*/
