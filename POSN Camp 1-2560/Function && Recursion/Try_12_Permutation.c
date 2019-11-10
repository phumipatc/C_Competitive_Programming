/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int n,r,k,count=0,a[15],b[15];
void permute(int state){
    int i;
    if(state==r){
        count++;
        if(count==k){
            for(i=0;i<r;i++){
                printf("%d ",b[i]);
            }
        }
        return ;
    }
    for(i=0;i<n;i++){
        if(a[i]!=-1){
            a[i]=-1;
            b[state]=i+1;
            permute(state+1);
            a[i]=0;
        }
    }
}
int main()
{
    scanf("%d %d %d",&n,&r,&k);
    permute(0);
    return 0;
}
