#include<stdio.h>
int a[30][30];
int main(){
    int n,m,i,j;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d ",a[i][j]);
        }
    }
    printf("\n");
    for(i=n-1;i>=0;i--){
        for(j=m-1;j>=0;j--){
            printf("%d ",a[i][j]);
        }
    }
    printf("\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d ",a[j][i]);
        }
    }
    printf("\n");
    for(i=m-1;i>=0;i--){
        for(j=n-1;j>=0;j--){
            printf("%d ",a[j][i]);
        }
    }
    printf("\n");
    return 0;
}
