/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1000100];
int main()
{
    long long maxx=-1,m,n,i;
    scanf("%lld %lld",&m,&n);
    for(i=1;i<=m;i++){
        scanf("%lld",&a[i]);
        maxx=max(maxx,a[i]);
    }
    long long l=1,r=maxx*n;
    while(l<r){
        long long sum=0;
        long long mid=(l+r)/2;
        for(i=1;i<=m;i++)
            sum+=mid/a[i];
        if(sum>=n)  r=mid;
        if(sum<n)   l=mid+1;
    }
    printf("%lld\n",l);
    return 0;
}
