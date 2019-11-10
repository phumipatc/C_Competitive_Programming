/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int n,r,k,count=0,a[15],b[15];
void combine(int state,int start){
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
    for(i=start;i<n;i++){
        if(a[i]!=-1){
            a[i]=-1;
            b[state]=i+1;
            combine(state+1,start+1);
            a[i]=0;
        }
    }
}
int main()
{
    scanf("%d %d %d",&n,&r,&k);
    combine(0,0);
    return 0;
}
