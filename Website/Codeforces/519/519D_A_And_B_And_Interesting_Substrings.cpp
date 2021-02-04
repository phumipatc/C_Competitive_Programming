/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long v[30],qs[100010],comp[100010],countt[30][100010];
char a[100010];
int main(){
    long long n,idx,ans = 0;
    for(long long i=0;i<26;i++)
        scanf("%lld",&v[i]);
    scanf(" %s",a+1);
    n = strlen(a+1);
    for(long long i=1;i<=n;i++){
        qs[i] = qs[i-1]+v[a[i]-'a'];
        comp[i] = qs[i];
    }
    sort(comp+1,comp+n+1);
    for(long long i=1;i<=n;i++){
        idx = lower_bound(comp+1,comp+n+1,qs[i-1])-comp;
        ans+=countt[a[i]-'a'][idx];
        // printf("answer: %c %lld %lld\n",a[i],idx,countt[a[i]-'a'][idx]);
        idx = lower_bound(comp+1,comp+n+1,qs[i])-comp;
        countt[a[i]-'a'][idx]++;
        // printf("update: %c %lld %lld\n",a[i],idx,countt[a[i]-'a'][idx]);
    }
    printf("%lld\n",ans);
	return 0;
}