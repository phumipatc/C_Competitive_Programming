/*
TASK: Ninja Power
LANG: C
AUTHOR: PeaTT~
*/
#include <stdio.h>
int ninja[1<<21],i,j,n,m,k,a,b,sum;
int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&ninja[i]);
    for(i=n-1;i>=0;i--)
    {
        sum+=ninja[i];
        if(ninja[i]!=0 && i*2+1<n)
            ninja[i]+=ninja[i*2+1];
        if(ninja[i]!=0 && i*2+2<n)
            ninja[i]+=ninja[i*2+2];
    }
    scanf("%d",&k);
    printf("%d\n",sum);
    for(i=0;i<k;i++)
    {
        scanf("%d %d",&a,&b);
        if(ninja[a]==ninja[b])
            printf("%d=%d\n",a,b);
        else if(ninja[a]<ninja[b])
            printf("%d<%d\n",a,b);
        else
            printf("%d>%d\n",a,b);
    }
    return 0;
}
