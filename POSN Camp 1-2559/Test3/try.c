/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[3000];
int main()
{
    int n,i,j,sum=0,max=-1,start=0,end,truthstart=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        sum+=a[i];
        if(sum>=0){
            if(sum>max){
                max=sum;
                truthstart=start;
                end=i;
            }
        }else{
            sum=0;
            start=i+1;
        }
    }
    if(max<=0){
        printf("Empty sequence");
    }else{
        for(i=truthstart;i<=end;i++)
            printf("%d ",a[i]);
            printf("\n%d\n",max);
    }
return 0;
}
