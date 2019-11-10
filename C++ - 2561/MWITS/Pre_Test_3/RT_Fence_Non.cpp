/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[300010],b[300010],c[300010],mark[300010];
int main(){
    long long n,l,r;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&b[i]);
    sort(b+1,b+n+1);
    l = 1,r = n;
    
    for(long long i=2;i<n;i++){
        if(a[i]>a[i-1] && a[i]>a[i+1])      mark[i] = b[r--];
        else if(a[i]<a[i-1] && a[i]<a[i+1]) mark[i] = b[l++];
    }
    if(a[1]<a[2])   mark[1] = b[l++];
    else            mark[1] = b[r--];
    if(a[n]>a[n-1]) mark[n] = b[r--];
    else            mark[n] = b[l++];
    l = 1;
    for(long long i=1;i<=n;i++){
        if(!mark[i])    continue;
        c[l++] = mark[i];
    }
    long long ans = 0;
    for(long long i=2;i<l;i++)
        ans+=abs(c[i]-c[i-1]);
    printf("%lld\n",ans);
	return 0;
}
