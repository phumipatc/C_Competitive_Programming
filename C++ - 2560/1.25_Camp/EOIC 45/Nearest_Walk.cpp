/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,state;
};
queue< A> a;
char b[1010][1010];
int d[1010][1010],di[4]={1,-1,0,0},dj[4]={0,0,1,-1};
void doo(){
    while(!a.empty())
        a.pop();
    memset(d,0,sizeof d);
    int r,c,i,j,sti,stj,eni,enj,nowi,nowj,nowstate,nexti,nextj,k;
    A temp;
    scanf("%d %d",&r,&c);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf(" %c",&b[i][j]);
            if(b[i][j]=='A')
                sti=i,stj=j;
            if(b[i][j]=='B')
                eni=i,enj=j;
        }
    }
    temp.i=sti,temp.j=stj,temp.state=0;
    a.push(temp);
    d[sti][stj]=1;
    while(!a.empty()){
        nowi=a.front().i,nowj=a.front().j,nowstate=a.front().state;
        a.pop();
        if(nowi==eni && nowj==enj){
            printf("%d\n",nowstate);    return ;
        }
        for(k=0;k<4;k++){
            nexti = nowi+di[k], nextj = nowj+dj[k];
            if(nexti<0||nextj<0||nexti>=r||nextj>=c)    continue;
            if(d[nexti][nextj]==1)  continue;
            if(b[nexti][nextj]=='#')    continue;
            d[nexti][nextj]=1;
            temp.i=nexti,temp.j=nextj,temp.state=nowstate+1;
            a.push(temp);
        }
    }
    printf("-1\n");
}
int main()
{
    int Q;
    scanf("%d",&Q);
    while(Q--)
        doo();
    return 0;
}
/*
2 4 5
#A.#. ..#.B .#..# ....#
4 5
#A.#. ..#.B .#..# ..#.#
*/
