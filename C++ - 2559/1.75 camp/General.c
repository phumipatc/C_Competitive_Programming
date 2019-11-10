#include<stdio.h>
int p[100100],nub[100100];
int findroot(int i)
{
    if(p[i]==i)
        return p[i];
    return p[i]=findroot(p[i]);
}
int main()
{
    int n,q,i,a,b,roota,rootb;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++)
        p[i]=i;
    for(i=1;i<=n;i++)
        scanf("%d",&nub[i]);
    while(q--)
    {
        scanf("%d %d",&a,&b);
        roota=findroot(a);
        rootb=findroot(b);
        if(roota==rootb)
            printf("-1\n");
        else
        {
            if(nub[roota]>nub[rootb])
            {
                printf("%d\n",roota);
                nub[roota]+=nub[rootb]/2;
                p[rootb]=roota;
            }
            else if(nub[rootb]>nub[roota])
            {
                printf("%d\n",rootb);
                nub[rootb]+=nub[roota]/2;
                p[roota]=rootb;
            }
            else
            {
                if(roota>rootb)
                {
                    printf("%d",rootb);
                    nub[rootb]+=nub[roota]/2;
                    p[roota]=rootb;
                }
                else
                {
                    printf("%d\n",roota);
                    nub[roota]+=nub[rootb]/2;
                    p[rootb]=roota;
                }
            }
        }
    }
    return 0;
}

