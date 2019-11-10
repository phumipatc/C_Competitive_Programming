/*
    TASK :
    AUTHOR : Phumipat C.
    SCHOOL : RYW
    LANG : C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j;
};
A now;
char a[110][110];
int dis[110][110],dir[4]={1,-1,0,0},dic[4]={0,0,1,-1};
queue< A> que;
int main()
{
    int k,ch=1,r,c,i,j,sti,stj,eni,enj;
    scanf("%d %d",&c,&r);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf(" %c",&a[i][j]);
            if(a[i][j]=='M' && ch==1)       sti=i,stj=j,ch=2;
            else if(a[i][j]=='M' && ch==2)  eni=i,enj=j;
        }
    }
    que.push({sti,stj});
    while(!que.empty()){
        now = que.front();
        que.pop();
        if(now.i == eni && now.j == enj){
            printf("%d\n",dis[eni][enj]-1);
            break;
        }
        for(k=0;k<4;k++){
            for(i=now.i+dir[k],j=now.j+dic[k];;i+=dir[k],j+=dic[k]){
                if(i<0 || j<0 || i>=r || j>=c)  break;
                if(a[i][j] == '*')  break;
                if(dis[i][j])                   continue;
                dis[i][j] = dis[now.i][now.j]+1;
                que.push({i,j});
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
