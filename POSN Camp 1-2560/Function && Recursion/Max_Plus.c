/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
#include<math.h>
int a[1200][1200];
int main()
{
    int n,m,i,j,sum=0,max=-1,mi,mj;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            sum=0;
            sum+=a[i][j];
            if(i-2>0)  sum+=a[i-2][j];
            if(i-1>0)  sum+=a[i-1][j];
            if(i+1<=n)   sum+=a[i+1][j];
            if(i+2<=n)  sum+=a[i+2][j];
            if(j-2>0)  sum+=a[i][j-2];
            if(j-1>0)  sum+=a[i][j-1];
            if(j+1<=m)   sum+=a[i][j+1];
            if(j+2<=m)  sum+=a[i][j+2];
            if(sum>max){
                max=sum;
                mi=i;
                mj=j;
            }
        }
    }
    printf("%d\n%d %d",max,mi,mj);
    return 0;
}
