/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
long long s,sum,a[1000100],maxx;
int main()
{
    int q,i,n;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        sum=0,s=0,maxx=-10000000;
        for(i=0;i<n;i++){
            scanf("%lld",&a[i]);
            if(i%2==0) a[i]*=-1;
            sum+=a[i];
        }
        for(i=0;i<n;i++){
            s+=a[i];
            if(s<0)   s=0;
            maxx=max(maxx,s);
        }
        printf("%lld\n",sum-(2*maxx));
    }
    return 0;
}
