/*
    TASK:Limbo
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
char a[100][100];
char b[100][100];
int sum,n,m;
void play(int i,int j){
    if(i-1>=0 && b[i-1][j]=='.'){
        b[i-1][j]='#';  sum++;
        play(i-1,j);
    }
    if(j-1>=0 && b[i][j-1]=='.'){
        b[i][j-1]='#';  sum++;
        play(i,j-1);
    }
    if(i+1<n && b[i+1][j]=='.'){
        b[i+1][j]='#';  sum++;
        play(i+1,j);
    }
    if(j+1<m && b[i][j+1]=='.'){
        b[i][j+1]='#';  sum++;
        play(i,j+1);
    }
}
int main()
{
    int i,j,max=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf(" %c",&a[i][j]);
            b[i][j]=a[i][j];
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(a[i][j]=='#'){
                if(i-1>=0)  b[i-1][j]='#';
                if(j-1>=0)  b[i][j-1]='#';
                if(i+1<n)   b[i+1][j]='#';
                if(j+1<m)   b[i][j+1]='#';
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(b[i][j]=='.'){
                sum=1;
                b[i][j]='#';
                play(i,j);
                if(sum>max)
                    max=sum;
            }
        }
    }
    printf("%d",max);
return 0;
}
/*
4 6
..#...
...##.
..#..#
.#...#
*/
