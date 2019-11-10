/*
    TASK:
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
    int n,i,j,r,k;
    scanf("%d %d %d",&n,&r,&k);
    for(i=2;i<=n;i++){
        a[i%2][0]=1;
        for(j=1;j<i;j++){
            a[i%2][j]=a[(i-1)%2][j]+a[(i-1)%2][j-1];
            a[i%2][j]%=k;
        }
        a[i%2][i]=1;
    }
        printf("%d\n",a[n%2][r]%k);
return 0;
}
