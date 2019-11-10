/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long countt[100010],a[1000010];
int main(){
    long long n,m,ans = 0;
    scanf("%lld",&n);
    for(long long i=0;i<n;i++){
        scanf("%lld",&a[i]);
        countt[a[i]]++;
    }
    scanf("%lld",&m);
    sort(a,a+n);
    for(long long i=0;i<n;i++){
        if(a[i] == a[i+1])  continue;
        if(a[i] != m-a[i])  ans+=countt[a[i]]*countt[m-a[i]];
        else                ans+=countt[a[i]]*(countt[a[i]]-1);
    }
    printf("%lld\n",ans/2);
	return 0;
}
