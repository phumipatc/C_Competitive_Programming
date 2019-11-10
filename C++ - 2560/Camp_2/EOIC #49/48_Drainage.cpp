/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int mark[110][110];
char a[110][110];
queue < pair<int,int> > bfs;
int main()
{
    int n,m,i,j,nowi,nowj;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf(" %c",&a[i][j]),mark[i][j]=1000000;
    mark[1][1]=1;
    bfs.push(make_pair(1,1));
    while(!bfs.empty()){
        nowi =bfs.front().first,nowj=bfs.front().second;
        bfs.pop();
        if((a[nowi][nowj]=='R'||a[nowi][nowj]=='B') && nowj+1<=m && mark[nowi][nowj]<mark[nowi][nowj+1]){
            if(mark[nowi][nowj]+1==mark[nowi][nowj+1]){
                printf("%d\n%d %d\n",mark[nowi][nowj+1],nowi,nowj+1);
                return 0;
            }
            mark[nowi][nowj+1]=mark[nowi][nowj]+1;
            bfs.push(make_pair(nowi,nowj+1));
        }
        if((a[nowi][nowj]=='D'||a[nowi][nowj]=='B') && nowi+1<=n && mark[nowi][nowj]<mark[nowi+1][nowj]){
            if(mark[nowi][nowj]+1==mark[nowi+1][nowj]){
                printf("%d\n%d %d\n",mark[nowi+1][nowj],nowi+1,nowj);
                return 0;
            }
            mark[nowi+1][nowj]=mark[nowi][nowj]+1;
            bfs.push(make_pair(nowi+1,nowj));
        }
        if(nowj-1>=1 && (a[nowi][nowj-1]=='R'||a[nowi][nowj-1]=='B') && mark[nowi][nowj]<mark[nowi][nowj-1]){
            if(mark[nowi][nowj]+1==mark[nowi][nowj-1]){
                printf("%d\n%d %d\n",mark[nowi][nowj-1],nowi,nowj-1);
                return 0;
            }
            mark[nowi][nowj-1]=mark[nowi][nowj]+1;
            bfs.push(make_pair(nowi,nowj-1));
        }
        if(nowi-1>=1 && (a[nowi-1][nowj]=='D'||a[nowi-1][nowj]=='B') && mark[nowi][nowj]<mark[nowi-1][nowj]){
            if(mark[nowi][nowj]+1==mark[nowi-1][nowj]){
                printf("%d\n%d %d\n",mark[nowi-1][nowj],nowi-1,nowj);
                return 0;
            }
            mark[nowi-1][nowj]=mark[nowi][nowj]+1;
            bfs.push(make_pair(nowi-1,nowj));
        }
    }
    return 0;
}
/*
4 4
B R D N
D R B D
R R R D
N N N N

3 4
B B B D
D N R B
R R R N
*/
