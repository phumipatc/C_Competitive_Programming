#include<stdio.h>
#include<math.h>
int main()
{
   int m,n,k,i,j,p;
   scanf("%d %d",&n,&m);
   int a[150][150];
   int f[30],b[30],c[30];
   for(i=0;i<=n-1;i++){
        for(j=0;j<=m-1;j++)
        scanf("%d",&a[i][j]);

   }
   scanf("%d",&k);
   for(i=0;i<k;i++){
        scanf("%d %d %d",&f[i],&b[i],&c[i]);
            if(f[i]==1){
                for(j=0;j<m;j++)
                    a[b[i]-1][j]=c[i];
            }else{
                for(p=0;p<n;p++)
                    a[p][b[i]-1]=c[i];
            }
        }
            for(i=0;i<=n-1;i++){
                for(j=0;j<=m-1;j++){
            printf("%d ",a[i][j]);
                }
            printf("\n");
            }
return 0;
}
