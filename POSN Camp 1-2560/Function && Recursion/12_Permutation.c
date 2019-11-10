/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
#include<stdlib.h>
int n,r,k,count,a[20],b[20];
void permute(int state){
    int i;
    if(state==r){
        count++;
        if(count==k){
            for(i=0;i<r-1;i++)
                printf("%d ",b[i]);
            printf("%d\n",b[i]);
            exit(0);
        }
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
    scanf("%d %d %d",&n,&r,&k);
    count=0;
    permute(0);
    return 0;
}
