#include<bits/stdc++.h>
using namespace std;
int _pow[1100];
int a[1100];
int att(int now,int hit)
{
    if(_pow[now]<=0||hit==0)
    {
        _pow[now] = 0;
        return 1;
    }
    _pow[now]-=hit;
    if(att(a[now],hit))
        return 1;
    return 0;
}
int main()
{
    int Q,n,m,st,hit;
    scanf("%d",&Q);
    while(Q--)
    {
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d %d",&_pow[i],&a[i]);
        while(m--)
        {
            scanf("%d %d",&st,&hit);
            while(1)
            {
                if(att(st,hit))
                    break;
            }
            for(int i=0;i<n;i++)
            {
                printf("%d ",_pow[i]*(_pow[i]>0));
            }
            printf("\n");
        }
    }
    return 0;
}
