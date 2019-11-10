/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
long long times[1000100];
int main()
{
    long long maxx=-1,m,n,i,l,r,mid,sum;
    scanf("%lld %lld",&m,&n);
    for(i=1;i<=m;i++){
        scanf("%lld",&times[i]);
        maxx=max(maxx,times[i]);
    }
    l=1,r=maxx*n;
    while(l<r){
        sum=0;
        mid=(l+r)/2;
        for(i=1;i<=m;i++)
            sum+=mid/times[i];
        if(sum>=n)  r=mid;
        if(sum<n)   l=mid+1;
    }
    printf("%lld\n",r);
    return 0;
}
