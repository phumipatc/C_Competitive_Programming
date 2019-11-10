#include<bits/stdc++.h>
using namespace std;
#define N 1000005
long long sum[N];
int main()
{
    long long q,n,num;
    sum[1]=1;
    sum[2]=3;
    for(long long i=3;i<=1000000;i++)
    {
        long long l=1,r=i-1;
        while(l<r)
        {
            long long mid=(l+r)/2;
            if(sum[mid]<i)  l=mid+1;
            else             r=mid;
        }
        sum[i]=l+sum[i-1];
        if(sum[i]>2e9)
        {
            n=i;
            break;
        }
    }
    scanf("%lld",&q);
    while(q--)
    {
        scanf("%lld",&num);
        long long l=1,r=n;
        while(l<r)
        {
            long long mid=(l+r)/2;
            if(sum[mid]<num)    l=mid+1;
            else                r=mid;
        }
        printf("%lld\n",l);
    }
    return 0;
}
