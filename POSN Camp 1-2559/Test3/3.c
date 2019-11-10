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
    int n,i,j,sum,max=-1,start,end;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
            sum=0;
        for(j=i;j<n;j++){
            sum+=a[j];
            if(sum>max){
                max=sum;
                start=i;
                end=j;
            }
        }
    }
    if(max<=0){
        printf("Empty sequence");
    }else{
        for(i=start;i<=end;i++)
            printf("%d ",a[i]);
            printf("\n%d\n",max);
    }
return 0;
}
