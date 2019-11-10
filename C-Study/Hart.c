#include<stdio.h>
int a[120][120];
int main(){
    int n,m,opr,k,i,j,r,s;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    scanf("%d",&r);
    while(r--){
        scanf("%d",&opr);
        if(opr==1){
            scanf("%d %d",&i,&k);
            i-=1;
            for(j=0;j<m;j++)
                a[i][j]=k;
        }else if(opr==2){
            scanf("%d %d",&j,&k);
            j-=1;
            for(i=0;i<n;i++)
                a[i][j]=k;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
