/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[800][800];
int sum=0,h,w;
void play(int i,int j)
{
    if(i-1>=0 && a[i-1][j]=='.'){
        a[i-1][j]='*';  sum++;
        play(i-1,j);
    }
    if(j-1>=0 && a[i][j-1]=='.'){
        a[i][j-1]='*'; sum++;
        play(i,j-1);
    }
    if(i+1<h && a[i+1][j]=='.'){
        a[i+1][j]='*';  sum++;
        play(i+1,j);
    }
    if(j+1<w && a[i][j+1]=='.'){
        a[i][j+1]='*';  sum++;
        play(i,j+1);
    }

    if(i-1>=0 && j-1>=0 && a[i-1][j-1]=='.'){
        a[i-1][j-1]='*';  sum++;
        play(i-1,j-1);
    }
    if(i+1<h && j-1>=0 && a[i+1][j-1]=='.'){
        a[i+1][j-1]='*'; sum++;
        play(i+1,j-1);
    }
    if(i+1<h && j+1<w && a[i+1][j+1]=='.'){
        a[i+1][j+1]='*';  sum++;
        play(i+1,j+1);
    }
    if(i-1>=0 && j+1<w && a[i-1][j+1]=='.'){
        a[i-1][j+1]='*';  sum++;
        play(i-1,j+1);
    }
}
int main()
{
    int i,j,maxx=0;
    scanf("%d %d",&w,&h);
    for(i=0;i<h;i++)
            scanf(" %s",&a[i]);
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            if(a[i][j]=='.'){
                sum=1;
                a[i][j]='*';
                play(i,j);
                maxx=max(maxx,sum);
            }
        }
    }
    printf("%d\n",maxx);
    return 0;
}
/*
10 8
...*....**
..**....**
...*....**
...**.*.**
***.**.***
...**.*.**
...*.*****
...***..**
*/
