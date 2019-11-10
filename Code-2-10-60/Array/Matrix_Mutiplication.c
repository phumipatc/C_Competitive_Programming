/*
    Task :
    Author : Boss
    School : RYW
    Language : C
*/
#include<stdio.h>
int a[15][15],b[15][15],c[15][15];
int main()
{
    int i,j,n1,n2,m1,m2,k;
    scanf("%d %d %d %d",&n1,&m1,&n2,&m2);
    if(m1!=n2){
        printf("Can't Multiply.");
        return 0;
    }
    for(i=0;i<n1;i++){
        for(j=0;j<m1;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n2;i++){
        for(j=0;j<m2;j++){
            scanf("%d",&b[i][j]);
        }
    }
    for(i=0;i<n1;i++){
        for(j=0;j<m2;j++){
            for(k=0;k<=m1;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    for(i=0;i<n1;i++){
        for(j=0;j<m2;j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}
/*
2 3 3 2
4 5 -2
3 -4 1
-1 2
-5 -3
3 -6
*/
