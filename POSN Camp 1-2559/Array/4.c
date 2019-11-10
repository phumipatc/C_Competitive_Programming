#include<stdio.h>
#include<math.h>
char a[120][120];
int main()
{
   int n,m,x,y,i,j,c,d;
   scanf("%d %d %d %d",&n,&m,&x,&y);
    for(i=0;i<=n-1;i++){
        for(j=0;j<=m-1;j++)
        scanf(" %c",&a[i][j]);
    }
    for(i=0;i<n;i++){
        for(c=0;c<x;c++){
            for(j=0;j<m;j++){
                for(d=0;d<y;d++){
                    printf("%c",a[i][j]);
                }
            }
            printf("\n");
        }
    }
return 0;
}
