/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[30100];
int main()
{
    long long n,ans=0,maxx=-1;
    cin >> n;
    if(n < 3)
    {
        printf("%lld\n",n);
        return 0;
    }
    for(long long i=1; i<=n; i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    for(long long i=1; i<=n; i++)
    {
        long long idx=lower_bound(a+1,a+n+1,a[i]+a[i+1])-a;
        ans = (idx-1)-i+1;
        if(ans >= 3)
            maxx=max(maxx,ans);
    }
    printf("%lld\n",maxx);
    return 0;
}
/*
10
7 1 2 8 10 6 1 7 9 9
*/
