/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
#include<stdlib.h>
int n,r,a[10],b[10],c[10];
void permute(int state){
    int i;
    if(state==r){
        for(i=0;i<r;i++)
            printf("%d ",c[b[i]]);
        printf("\n");
        return ;
    }else{
        for(i=0;i<n;i++){
            if(a[i]!=-1){
                a[i]=-1;
                b[state]=i+1;
                permute(state+1);
                a[i]=0;
            }
        }
    }
}
int main()
{
    int q,i;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        r=n;
        for(i=1;i<=n;i++){
            scanf("%d",&c[i]);
        }
        permute(0);
    }
    return 0;
}
