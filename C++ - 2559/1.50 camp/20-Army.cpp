/*
    TASK: Army
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[1000][1000];
struct A{
    int i,j;
};
typedef struct A A;
queue< A> que;
main(){
    int r,c,i,j,count,nowi,nowj,max=0;
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
                a[i][j]='*';
                count=1;
                que.push(temp);
                while(!que.empty()){
                    nowi=que.front().i;
                    nowj=que.front().j;
                    que.pop();
                    if(nowi-1>=0 && a[nowi-1][nowj]=='.'){
                        temp.i=nowi-1;
                        temp.j=nowj;
                        a[nowi-1][nowj]='*';
                        count++;
                        que.push(temp);
                    }
                    if(nowj-1>=0 && a[nowi][nowj-1]=='.'){
                        temp.i=nowi;
                        temp.j=nowj-1;
                        a[nowi][nowj-1]='*';
                        count++;
                        que.push(temp);
                    }
                    if(nowi+1<r && a[nowi+1][nowj]=='.'){
                        temp.i=nowi+1;
                        temp.j=nowj;
                        a[nowi+1][nowj]='*';
                        count++;
                        que.push(temp);
                    }
                    if(nowj+1<c && a[nowi][nowj+1]=='.'){
                        temp.i=nowi;
                        temp.j=nowj+1;
                        a[nowi][nowj+1]='*';
                        count++;
                        que.push(temp);
                    }
                    if(nowi-1>=0 && nowj-1>=0 && a[nowi-1][nowj-1]=='.'){
                        temp.i=nowi-1;
                        temp.j=nowj-1;
                        a[nowi-1][nowj-1]='*';
                        count++;
                        que.push(temp);
                    }
                    if(nowi-1>=0 && nowj+1<c && a[nowi-1][nowj+1]=='.'){
                        temp.i=nowi-1;
                        temp.j=nowj+1;
                        a[nowi-1][nowj+1]='*';
                        count++;
                        que.push(temp);
                    }
                    if(nowi+1<r && nowj-1>=0 && a[nowi+1][nowj-1]=='.'){
                        temp.i=nowi+1;
                        temp.j=nowj-1;
                        a[nowi+1][nowj-1]='*';
                        count++;
                        que.push(temp);
                    }
                    if(nowi+1<r && nowj+1<c && a[nowi+1][nowj+1]=='.'){
                        temp.i=nowi+1;
                        temp.j=nowj+1;
                        a[nowi+1][nowj+1]='*';
                        count++;
                        que.push(temp);
                    }
                }
                if(count>max)
                    max=count;
            }
        }
    }
    printf("%d",max);
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
