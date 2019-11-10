/*
    TASK:
    AUTHOR:
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
char a[500][500];
int main()
{
    int v,n,i,k,p,j;
    scanf("%d %d",&n,&k);
    if(n%k==0){
        v=(n/k);
    }else{
        v=(n/k)+1;
    }

    for(i=0;i<v;i++){
            for(j=0;j<v;j++){
        scanf(" %s",&a[i][j]);
            }
    }
    for(i=0;i<v;i++){
            for(j=0;j<v;j++){
                printf("%s",a[i][j]);
            }
    }
return 0;
}
