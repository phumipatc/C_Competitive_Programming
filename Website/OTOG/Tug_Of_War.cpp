/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[2100],b[2100];
int main()
{
    int n,i;
    long long ans = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++)    scanf("%d",&a[i]);
    for(i=0;i<n;i++)    scanf("%d",&b[i]);
    sort(a,a+n);
    sort(b,b+n);
    for(i=0;i<n;i++)    ans+=abs(a[i]-b[i]);
    printf("%lld\n",ans);
    return 0;
}
