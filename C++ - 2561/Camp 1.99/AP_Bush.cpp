/*
    TASK: AP_Bush
    LANG: CPP
    AUTHOR: Phumipat C.
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1005];
int main()
{
    long long q,r,l,n,k,i,mid,coun,d;
    scanf("%lld",&q);
    while(q--)
    {
        scanf("%lld %lld",&n,&k);
        for(i=0; i<n; i++)
            scanf("%lld",&a[i]);
        sort(a,a+n);
        r=0,l=1000000000;
        while(r<l)
        {
            mid=(r+l)/2;
            coun=(mid+1)*(mid+1)*n;
            for(i=1; i<n; i++)
            {
                if(a[i]==a[i-1])
                {
                    coun-=(mid+1)*(mid+1);
                    continue;
                }
                d=a[i]-a[i-1]-1;
                if(d%2)
                {
                    d/=2;
                    if(d<mid)
                    {
                        d=mid-d;
                        coun-=(d*(d+1))/2+(d*(d-1))/2;
                    }
                }
                else
                {
                    d/=2;
                    if(d<mid)
                    {
                        d=mid-d;
                        coun-=d*(d+1);
                    }
                }
            }
            if(coun<k)
                r=mid+1;
            else
                l=mid;
        }
        printf("%lld\n",r);
    }
}
