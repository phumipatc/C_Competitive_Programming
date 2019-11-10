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
char a[1100][1100];
int mark[1100][1100],dir[2][4]{{1,-1,0,0},{0,0,1,-1}};
queue< A> que;
int main(){
    int q,n,m,sti,stj,eni,enj,nexti,nextj;
    scanf("%d",&q);
    while(q--){
        memset(mark,0,sizeof mark);
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf(" %c",&a[i][j]);
                if(a[i][j]=='A')
                    sti=i,stj=j;
                else if(a[i][j]=='B')
                    eni=i,enj=j;
            }
        }
        int ch=1;
        mark[sti][stj]=1;
        que.push({sti,stj,0});
        while(!que.empty()){
            A now=que.front();
            que.pop();
            if(now.i==eni && now.j==enj){
                printf("%d\n",now.dis);
                ch=0;
                break;
            }
            for(int k=0;k<4;k++){
                nexti=now.i+dir[0][k];
                nextj=now.j+dir[1][k];
                if(a[nexti][nextj]=='#')    continue;
                if(mark[nexti][nextj]==1)   continue;
                if(nexti<1 || nextj<1 || nexti>n || nextj>m)    continue;
                mark[nexti][nextj]=1;
                que.push({nexti,nextj,now.dis+1});
            }
        }
        if(ch)  printf("-1\n");
        while(!que.empty())
            que.pop();
    }
    return 0;
}
