/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100010],l[100010],r[100010];
int main(){
    long long q,n,ans,sum;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        for(long long i=1;i<=n;i++)
            scanf("%lld",&a[i]);

        sum = 0;
        for(long long i=1;i<=n;i++){
            sum+=a[i];
            sum = max(sum,0ll);
            l[i] = max(l[i-1],sum);
        }
        sum = 0;
        for(long long i=n;i>=1;i--){
            sum+=a[i];
            sum = max(sum,0ll);
            r[i] = max(r[i+1],sum);
        }
        ans = 0;
        for(long long i=1;i<=n;i++)
            ans = max(ans,l[i]+r[i+1]);
        printf("%lld\n",ans);

        memset(l,0,sizeof l);
        memset(r,0,sizeof r);
    }
	return 0;
}
