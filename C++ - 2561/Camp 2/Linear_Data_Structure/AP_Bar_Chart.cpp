/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100010],l[100010],r[100010];
int main(){
    long long q,n,maxx;
    scanf("%lld",&q);
    while(q--){
        maxx = 0;
        scanf("%lld",&n);
        for(long long i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        for(long long i=1;i<=n;i++){
            l[i] = i-1;
            while(l[i]>0 && a[i]<=a[l[i]])  l[i] = l[l[i]];
        }
        for(long long i=n;i>=1;i--){
            r[i] = i+1;
            while(r[i]<=n && a[i]<=a[r[i]]) r[i] = r[r[i]];
        }
        for(long long i=1;i<=n;i++){
            maxx = max(maxx,(r[i]-l[i]-1)*a[i]);
        }
        printf("%lld\n",maxx);
        memset(a,0,sizeof a);
    }
	return 0;
}
