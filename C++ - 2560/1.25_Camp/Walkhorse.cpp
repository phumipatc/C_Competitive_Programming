/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j;
};
queue<A> q;
char a[1500][1500];
int dis[1500][1500];
int dir[8]={2,2,1,1,-1,-1,-2,-2},dic[8]={1,-1,2,-2,2,-2,1,-1};
int main(){
    A temp;
    int r,c,i,j,sti,stj,eni,enj,nowi,nowj,nexti,nextj;
    scanf("%d %d",&r,&c);
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
            scanf(" %c",&a[i][j]);
    scanf("%d %d %d %d",&sti,&stj,&eni,&enj);
    memset(dis,-1,sizeof(dis));
    if(a[sti][stj]=='X' || a[eni][enj]=='X'){
        printf("-1\n");
        return 0;
    }
    dis[sti][stj]=0;
    temp.i=sti,temp.j=stj;
    q.push(temp);
    while(!q.empty()){
        temp=q.front();
        q.pop();
        nowi=temp.i,nowj=temp.j;
        if(nowi==eni && nowj==enj)
            break;
        for(int k=0;k<8;k++){
            nexti=nowi+dir[k],nextj=nowj+dic[k];
            if(nexti<1 || nextj<1 || nexti>r || nextj>c || a[nexti][nextj]=='X' || dis[nexti][nextj]!=-1)    continue;
            dis[nexti][nextj]=dis[nowi][nowj]+1;
            temp.i=nexti,temp.j=nextj;
            q.push(temp);
        }
    }
    printf("%d\n",dis[eni][enj]);
return 0;
}
