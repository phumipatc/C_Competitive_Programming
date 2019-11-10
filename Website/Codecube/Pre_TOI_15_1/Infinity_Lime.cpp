/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long des[700010],a[700010],st[700010];
int main(){
    long long m,k,temp,idx;
    scanf("%lld %lld",&m,&k);
    for(long long i=1;i<=m;i++)
        scanf("%lld",&des[i]);
    sort(des+1,des+m+1);
    des[m+1] = 1e10;
    a[0] = des[1]-1;
    st[0] = 1;
    for(long long i=1;i<=m;i++){
        a[i] = a[i-1]+des[i+1]-des[i]-1;
        st[i] = des[i]+1;
        // printf("%lld %lld\n",a[i],st[i]);
    }
    for(long long i=1;i<=k;i++){
        scanf("%lld",&temp);
        idx = lower_bound(a,a+m+1,temp)-a;
        printf("%lld ",temp-a[idx-1]+st[idx]-1);
    }
	return 0;
}
