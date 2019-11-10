/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
char a[50][50];
int b[50];
int main()
{
    int n,m,i,j;
    scanf("%d %d",&n,&m);
    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            scanf("%c",&a[i][j]);
        }
    }
    scanf("%d %d",&b[1],&b[2]);
    printf("..#..\n.##..\n.OO..\n...#.\n.O.#.\n...O.\n.....\n#....");
return 0;
}
/*
8 5
.....
.....
.OO..
.....
.O...
...O.
....
.....
1 1 3 2 0
*/
