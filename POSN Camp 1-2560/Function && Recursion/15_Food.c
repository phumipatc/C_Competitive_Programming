/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int a[10],b[10],n,mark[10];
void food(int state){
    int i;
    if(state==n){
        for(i=0;i<n;i++)
            printf("%d ",b[i]);
        printf("\n");
        return ;
    }
    for(i=1;i<=n;i++){
        if(a[i]!=-1){
            a[i]=-1;
            b[state]=i;
            food(state+1);
            a[i]=0;
        }
    }
}
int main()
{
    int i,k;
    scanf("%d %d",&n,&k);
    while(k--){
        scanf("%d",&i);
        mark[i]=1;
    }
    for(i=1;i<=n;i++){
        if(mark[i]!=1){
            b[0]=i;
            a[i]=-1;
            food(1);
            a[i]=0;
        }
    }
    return 0;
}
