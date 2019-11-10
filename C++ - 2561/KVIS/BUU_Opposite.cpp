/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include <bits/stdc++.h>
using namespace std;
struct A{
    int i,j,k,l,t;
};
queue< A > q;
A temp;
char a[40][40];
int sp[40][40][40][40],mark[40][40][40][40],r,c;
int ni[4]={1,-1,0,0},nj[4]={0,0,1,-1},nk[4]={-1,1,0,0},nl[4]={0,0,-1,1};
int main()
{
    int Q,i,j,si,sj,ei,ej,nowi,nowj,nowt,k,nexti,nextj,nowk,nowl,nextk,nextl,mi,step;
    scanf("%d",&Q);
    while(Q--){
        scanf("%d %d",&r,&c);
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                scanf(" %c",&a[i][j]);
                if(a[i][j]=='A')    si=i,sj=j;
                if(a[i][j]=='B')    ei=i,ej=j;
            }
        }
        memset(sp,-1,sizeof sp);
        memset(mark,0,sizeof mark);
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                if(a[i][j]=='#')    continue;
                temp.i=i,temp.j=j,temp.t=0;
                mark[i][j][i][j]=1;
                sp[i][j][i][j]=0;
                q.push(temp);
                while(!q.empty()){
                    temp = q.front();   //dequeue
                    q.pop();
                    nowi=temp.i, nowj=temp.j, nowt=temp.t;
                    for(k=0;k<4;k++){
                        nexti = nowi+ni[k], nextj = nowj+nj[k];
                        if(nexti<0||nextj<0||nexti>=r||nextj>=c)    continue;
                        if(a[nexti][nextj]=='#')    continue;
                        if(mark[i][j][nexti][nextj])  continue;
                        mark[i][j][nexti][nextj]=1;
                        temp.i=nexti,temp.j=nextj,temp.t=nowt+1;
                        sp[i][j][nexti][nextj] = nowt+1;
                        q.push(temp);
                    }
                }
            }
        }
       /* for(i=0;i<r;i++){
            for(j=0;j<c;j++)
                printf("%d ",sp[1][4][i][j]);
            printf("\n");
        }*/
        //BFS Rob 2
        memset(mark,0,sizeof mark);
        temp.i=si,temp.j=sj,temp.k=ei,temp.l=ej,temp.t=0;
        q.push(temp);
        mi = 1<<30;
        mark[si][sj][ei][ej]=1;
     //   int cc=0;
        while(!q.empty()){
            temp = q.front();   //dequeue
            q.pop();
            nowi=temp.i,nowj=temp.j,nowk=temp.k,nowl=temp.l,nowt=temp.t;
            if(sp[nowi][nowj][nowk][nowl]<mi)  mi=sp[nowi][nowj][nowk][nowl],step=nowt;
            for(k=0;k<4;k++){
                nexti = nowi+ni[k], nextj = nowj+nj[k];
                nextk = nowk+nk[k], nextl = nowl+nl[k];
                if(nexti<0||nextj<0||nexti>=r||nextj>=c || a[nexti][nextj]=='#')
                    nexti=nowi,nextj=nowj;
                if(nextk<0||nextl<0||nextk>=r||nextl>=c || a[nextk][nextl]=='#')
                    nextk=nowk,nextl=nowl;
                if(mark[nexti][nextj][nextk][nextl])  continue;
                if(sp[nexti][nextj][nextk][nextl]==-1) continue;
                mark[nexti][nextj][nextk][nextl]=1;
                temp.i=nexti,temp.j=nextj,temp.k=nextk,temp.l=nextl,temp.t=nowt+1;
                q.push(temp);
            }
        }
        printf("%d %d\n",mi,step);
    }
    return 0;
}
/*
4 2 5 A.... ....B 1 5 A.#.B 1 5 A...B 3 5 A.... ###.. ###.B
*/
