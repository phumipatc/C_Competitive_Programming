#include<stdio.h>
char a[120][120];
int main(){
    int n,m,zn,zm,i,j,r,c;
    scanf("%d %d %d %d",&n,&m,&zn,&zm);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf(" %c",&a[i][j]);
        }
    }
    for(i=0;i<n;i++){
        for(r=0;r<zn;r++){
            for(j=0;j<m;j++){
                for(c=0;c<zm;c++){
                    printf("%c",a[i][j]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}
