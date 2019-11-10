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
queue< A> bfs;
int mark[35][35],a[35][35],dist[35][35],dir[4]= {0,0,-1,1},dic[4]= {1,-1,0,0};
int main()
{
    int q,t,r,c,i,j,sti,stj,eni,enj,nowi,nowj,nowdis,nexti,nextj,cnt=0;
    scanf("%d",&q);
    while(q--){
        cnt=0;
        memset(mark,0,sizeof mark);
        memset(a,0,sizeof a);
        scanf("%d %d %d",&r,&c,&t);
        for(i=1; i<=r; i++){
            for(j=1; j<=c; j++){
                scanf(" %c",&a[i][j]);
                dist[i][j]=1<<30;
            }
        }
        scanf("%d %d %d %d",&sti,&stj,&eni,&enj);
        if(a[sti][stj]=='#'){
            printf("-1\n");
            continue;
        }
        bfs.push({sti,stj,0});
        mark[sti][stj]=1;
        dist[i][j]=0;
        cnt++;
        A temp;
        while(!bfs.empty()){
            temp=bfs.front();
            nowi=temp.i,nowj=temp.j,nowdis=temp.dis;
            bfs.pop();
            for(int k=0;k<4;k++){
                nexti=nowi+dir[k],nextj=nowj+dic[k];
                if(nexti<=0 || nexti>r || nextj<=0 || nextj>c || a[nexti][nextj]=='#' || mark[nexti][nextj])    continue;
                mark[nexti][nextj]=1;
                dist[nexti][nextj]=nowdis+1;
                cnt++;
                bfs.push({nexti,nextj,nowdis+1});
            }
        }
        if(dist[eni][enj]>t)
            printf("-1\n");
        else if((t-dist[eni][enj])/2>cnt-dist[eni][enj]-1)
            printf("%d\n",cnt);
        else
            printf("%d\n",((t-dist[eni][enj])/2)+dist[eni][enj]+1);
    }
    return 0;
}
/*
3
5 8 9
#..#..#.
.#...##.
##.##..#
...##.##
##.#..##
4 3 2 4

4 5 100
.....
.####
...#.
#.##.
3 3 1 3

3 5 2
.....
.####
.....
3 3 1 3
*/
