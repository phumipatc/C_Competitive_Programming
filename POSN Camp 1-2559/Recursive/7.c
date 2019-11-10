/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int a[100][100];
int m,x,y,max=-10;
void play(int i,int j){
    if(a[i][j]>max) max=a[i][j];
    if(i-1>=0 && a[i-1][j]!=100 && a[i-1][j]>a[i][j])
        play(i-1,j);
    if(j-1>=0 && a[i][j-1]!=100 && a[i][j-1]>a[i][j])
        play(i,j-1);
    if(i+1<m && a[i+1][j]!=100 && a[i+1][j]>a[i][j])
        play(i+1,j);
    if(j+1<m && a[i][j+1]!=100 && a[i][j+1]>a[i][j])
        play(i,j+1);
}
int main()
{
    int i,j;
    scanf("%d %d %d",&m,&x,&y);
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    play(y-1,x-1);
    printf("%d",max);
return 0;
}
/*
4
2 1
100 1 3 8
0 2 1 4
2 3 5 100
0 8 8 100
*/
