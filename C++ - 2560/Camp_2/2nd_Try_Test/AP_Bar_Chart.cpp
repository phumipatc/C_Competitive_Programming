/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
long long l[100100],r[100100],height[100100];
int main()
{
    long long q,n,i,maxx;
    scanf("%lld",&q);
    while(q--){
        maxx=-1;
        scanf("%lld",&n);
        for(i=1;i<=n;i++)
            scanf("%lld",&height[i]);
        for(i=1;i<=n;i++){
            l[i]=i-1;
            while(l[i]>0 && height[i]<=height[l[i]])
                l[i]=l[l[i]];
        }
        for(i=n;i>0;i--){
            r[i]=i+1;
            while(r[i]<=n && height[i]<=height[r[i]])
                r[i]=r[r[i]];
        }
        for(i=1;i<=n;i++){
            maxx=max(maxx,(r[i]-l[i]-1)*height[i]);
        }
        printf("%lld\n",maxx);
        memset(height,0,sizeof height);
    }
    return 0;
}
