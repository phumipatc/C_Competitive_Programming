/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int a[120000]={0};
int main()
{
    int n,q,r,s,i,num;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&num);
        a[i]=a[i-1]+num;
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&r,&s);
        printf("%d\n",a[s]-a[r-1]);
    }
    return 0;
}
