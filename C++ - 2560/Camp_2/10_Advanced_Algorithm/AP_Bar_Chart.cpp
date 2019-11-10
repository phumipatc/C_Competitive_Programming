/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
long long l[100100],r[100100],a[100100];
int main()
{
    long long q,n,i,j,ans;
    scanf("%lld",&q);
    while(q--){
        ans=-1;
        scanf("%lld",&n);
        for(i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        for(i=1;i<=n;i++){
            l[i]=i-1;
            while(l[i]>0 && a[i]<=a[l[i]])
                l[i]=l[l[i]];
        }
        for(i=n;i>=0;i--){
            r[i]=i+1;
            while(r[i]<=n && a[i]<=a[r[i]])
                r[i]=r[r[i]];
        }
        for(i=1;i<=n;i++){
            ans=max(ans,a[i]*(r[i]-l[i]-1));
        }
        printf("%lld\n",ans);
    }
    return 0;
}
