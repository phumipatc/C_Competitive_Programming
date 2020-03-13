/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[100010];
int main(){
	// ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	LL q,n,p,minn,l,r;
	scanf("%lld",&q);
	for(LL z=1;z<=q;z++){
		scanf("%lld %lld",&n,&p);
		for(LL i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			a[i]+=a[i-1];
		}
		a[n+1] = 0;
		minn = 1e18;
		for(LL i=1;i<=n;i++){
			LL idx = lower_bound(a+1,a+n+1,a[i-1]+p)-a;
			if(a[idx]-a[i-1]>=p){
				if(minn>a[idx]-a[i-1]){
					minn = a[idx]-a[i-1];
					l = i,r = idx;
				}
			}
		}
		printf("Case #%lld: %lld %lld\n",z,l-1,r-1);
	}
	return 0;
}