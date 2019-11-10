/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
char a[110][110];
int dis[110][110],dir[4]={1,-1,0,0},dic[4]={0,0,1,-1};
queue< ii> bfs;
int main()
{
    int nowi,nowj,k,ch=1,r,c,i,j,sti,stj,eni,enj;
    scanf("%d %d",&c,&r);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf(" %c",&a[i][j]);
            if(a[i][j]=='M' && ch==1)       sti=i,stj=j,ch=2;
            else if(a[i][j]=='M' && ch==2)  eni=i,enj=j;
        }
    }
    bfs.push(make_pair(sti,stj));
    while(!bfs.empty()){
        nowi=bfs.front().first;
        nowj=bfs.front().second;
        bfs.pop();
        if(nowi==eni && nowj==enj){
            printf("%d\n",dis[eni][enj]-1);
            return 0;
        }
        for(k=0;k<4;k++){
            for(i=nowi+dir[k],j=nowj+dic[k];;i+=dir[k],j+=dic[k]){
                if(i<0 || j<0 || i>=r || j>=c)
                    break;
                if(a[i][j]=='*')
                    break;
                if(dis[i][j])
                    continue;
                dis[i][j]=dis[nowi][nowj]+1;
                bfs.push(make_pair(i,j));
            }
        }
    }
    return 0;
}
/*
7 8
.......
......M
......*
*****.*
....*..
....*..
.M..*..
.......
*/
