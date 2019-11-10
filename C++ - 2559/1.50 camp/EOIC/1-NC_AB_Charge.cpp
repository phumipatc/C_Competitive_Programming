/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int a[1000100]={0,0,1,1};
int main()
{
    int n,num,i;
    for(i=4;i<1000010;i++)
        a[i]=(a[i-1]+a[i-2])%100003;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&num);
        printf("%d %d\n",a[num],a[num+1]);
    }

    return 0;
}
