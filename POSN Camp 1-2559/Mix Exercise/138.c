/*
    TASK:PAsCaL tRIanGLe
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[2][10100];
int main()
{
    a[0][0]=a[1][0]=a[1][1]=1;
    int n,i,j;
    scanf("%d",&n);
    if(n==0){
        printf("1\n");
        return 0;
    }
    if(n==1){
        printf("1 1\n");
        return 0;
    }
    for(i=2;i<=n;i++){
        a[i%2][0]=1;
        for(j=1;j<i;j++){
            a[i%2][j]=a[(i-1)%2][j]+a[(i-1)%2][j-1];
            a[i%2][j]%=55555;
        }
        a[i%2][i]=1;
    }
    for(i=0;i<=n;i++){
        printf("%d ",a[n%2][i]%55555);
    }
return 0;
}
