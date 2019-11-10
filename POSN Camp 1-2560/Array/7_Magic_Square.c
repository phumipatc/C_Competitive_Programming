/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int a[50][50];
int main()
{
    int n,k,x,y=0,i,j;
    scanf("%d %d",&n,&k);
    x = 0,y = n/2;
    for(i=1;i<=n*n;i++){
        if(a[x][y] != 0){
            x++;
            y--;
            x++;
            x+=n;
            y+=n;
            x %= n;
            y %= n;
        }
        a[x][y] = k;
        k++;
        x--;
        y++;
        x+=n;
        y+=n;
        x %= n;
        y %= n;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
