/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1000010],n,p,l,r,mid,sum,i,ch=0;
int main()
{
    scanf("%lld %lld",&n,&p);
    for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
    l=0,r=1000000000;
    while(l<r){
        mid=(l+r+1)/2,sum=0;
        for(i=0;i<n;i++)
            sum+=(a[i]/mid);
        if(sum==p)  ch=1;
        if(sum>=p)  l=mid;
        else           r=mid-1;
    }
    printf((ch)?"YES\n%lld\n":"NO\n%lld\n",l);
	return 0;
}
