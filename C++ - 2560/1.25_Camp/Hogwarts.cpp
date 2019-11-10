/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<stdio.h>
int n,m,a[100][100],b[100][100],siz;
void play(int i,int j){
    if(i<0||j<0||i>=n||j>=m)    return ;
    siz++;
    if(i-1>=0 && b[i-1][j]==0 && a[i][j]&2){
        b[i-1][j]=1;    play(i-1,j);
    }
    if(j-1>=0 && b[i][j-1]==0 && a[i][j]&1){
        b[i][j-1]=1;    play(i,j-1);
    }
    if(i+1<n && b[i+1][j]==0 && a[i][j]&8){
        b[i+1][j]=1;    play(i+1,j);
    }
    if(j+1<m && b[i][j+1]==0 && a[i][j]&4){
        b[i][j+1]=1;    play(i,j+1);
    }
}
int main()
{
    int i,j,room=0,maxx=1;
    scanf("%d %d",&m,&n);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&a[i][j]);
            a[i][j]=15-a[i][j];
            b[i][j]=0;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(!b[i][j]){
                b[i][j]=1;
                siz=0;
                play(i,j);
                room++;
                if(siz>maxx)
                    maxx=siz;
            }
        }
    }
    printf("%d\n%d\n",room,maxx);
    return 0;
}
/*
7 4
11 6 11 6 3 10 6
7 9 6 13 5 15 5
1 10 12 7 13 7 5
13 11 10 8 10 12 13
*/
