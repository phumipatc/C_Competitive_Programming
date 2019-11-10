#include<stdio.h>
int main()
{
    int q,n,m;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d",&n,&m);
        n=n*(n+1)/2;
        m=m*(m+1)/2;
        printf("%d",n*m);
    }
    return 0;
}
