/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include <bits/stdc++.h>
using namespace std;
long long a[110],n,m,sum,p,q,mid,ma=0,coun;
int main()
{
    int i;
    scanf("%lld %lld",&m,&n);
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
        ma = max(ma,a[i]);
    }
    p=ma,q=1<<30;
    while(p<q){
        mid = (p+q)/2;
        sum=0,coun=1;
        for(i=0,sum=0;i<n;i++)
        {
            if(sum+a[i]>mid){
                coun++; sum=a[i];
            }
            else    sum+=a[i];
        }
        if(coun<=m)  q=mid;
        else        p=mid+1;
    }
    printf("%lld\n",p);
    return 0;
}
