/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int a[110000];
int main()
{
    int n,q,i,r,s,sum,num;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&num);
        a[i]=a[i-1]+num;
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&r,&s);
        for(i=r,sum=0;i<=s;i++)
            sum+=a[i];
        printf("%d\n",a[s]-a[r-1]);
    }
return 0;
}
