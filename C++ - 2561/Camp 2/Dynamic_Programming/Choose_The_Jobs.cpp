/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int st,en,w;
    bool operator < (const A&o) const{
        if(en!=o.en)    return en<o.en;
        else            return st<o.st;
    }
};
A a[100010];
int b[100010],dp[100010];
int main(){
    int n,idx;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d %d %d",&a[i].st,&a[i].en,&a[i].w);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        b[i] = a[i].en;
    for(int i=1;i<=n;i++){
        idx = lower_bound(b+1,b+n+1,a[i].st)-b-1;
        dp[i] = max(dp[i-1],dp[idx]+a[i].w);
    }
    printf("%d\n",dp[n]);
	return 0;
}
