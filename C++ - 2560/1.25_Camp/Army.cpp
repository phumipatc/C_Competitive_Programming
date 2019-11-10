/*
    TASK: Army
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[1000][1000];
int dir[8]={1,1,1,0,0,-1,-1,-1},dic[8]={1,0,-1,1,-1,1,0,-1};
struct A{
    int i,j;
};
typedef struct A A;
queue< A> que;
main(){
    int r,c,i,j,countt,nowi,nowj,maxx=0,nexti,nextj;
    A temp;
    scanf("%d %d",&c,&r);
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf(" %c",&a[i][j]);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(a[i][j]=='.'){
                temp.i=i;
                temp.j=j;
                a[i][j]='#';
                countt=1;
                que.push(temp);
                while(!que.empty()){
                    nowi=que.front().i;
                    nowj=que.front().j;
                    que.pop();
                    for(int k=0;k<8;k++){
                        nexti=nowi+dir[k],nextj=nowj+dic[k];
                        if(nexti<0 || nextj<0 || nexti>=r || nextj>=c || a[nexti][nextj]!='.')  continue;
                        countt++;
                        a[nexti][nextj]='#';
                        temp.i=nexti,temp.j=nextj;
                        que.push(temp);
                    }
                }
                if(countt>maxx)
                    maxx=countt;
            }
        }
    }
    /*
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%c ",a[i][j]);
        }
        printf("\n");
    }
    */
    printf("%d",maxx);
return 0;
}
/*
10 8
. . . * . . . . * *
. . * * . . . . * *
. . . * . . . . * *
. . . * * . * . * *
* * * . * * . * * *
. . . * * . * . * *
. . . * . * * * * *
. . . * * * . . * *
*/
