/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[1010][1010];
int main()
{
    int x,y,i,j,k,p,q;
    scanf("%d %d %d",&x,&y,&k);
    while(k--){
        scanf("%d %d",&p,&q);
        a[p+1][q+1]=-1;
    }
    if(a[1][1]!=-1)
        a[1][1]=1;
    for(i=0;i<=x+1;i++){
        for(j=1;j<=y+1;j++){
            if(a[i][j]==-1)
                a[i][j]=0;
            else{
                a[i][j]+=a[i-1][j]+a[i][j-1];
            }
            a[i][j]%=1000000;
        }
    }
    printf("%d\n",a[x+1][y+1]);
return 0;
}
