/*
    TASK:Prime
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<math.h>
#define MAX 10000000
int a[10000000];
int main()
{
    int i,n,j,count=1;
    scanf("%d",&n);
    if(n==1){
        printf("2\n");
        return 0;
    }
    for(i=3;i<MAX;i+=2){
        a[i]=1;
    }
    for(i=3;i<=sqrt(MAX);i+=2){
        if(a[i]==1){
            for(j=i*i;j<MAX;j+=i)
                a[j]=0;
        }
    }
    for(i=3;i<MAX;i+=2){
        if(a[i]==1)
            count++;
            if(count==n){
                printf("%d\n",i);
                return 0;
            }
    }
return 0;
}
