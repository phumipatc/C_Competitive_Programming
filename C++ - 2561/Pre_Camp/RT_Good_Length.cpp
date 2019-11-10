/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
	long long l,r,maxx,num;
};
A dp[1000010];
long long a[1000010];
int main(){
    long long n,m;
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
	}
	long long l = 1,r = n>>1,mid,sum,countt;
	while(l<r){
		mid = (l+r+1)>>1,sum = 0,countt = 1;
		memset(dp,0,sizeof dp);
		if(n%mid == 0){
			for(long long i=1;i<=n;i++){
				dp[countt].maxx = max(dp[countt].maxx,a[i]);
				if(i%mid == 0){
					sum+=dp[countt].maxx;
					countt++;
				}
			}
		}else{
			dp[1].l = 1;
			for(long long i=1;i<=n;i++){
				dp[countt].r = i;
				if(dp[countt].maxx<a[i]){
					dp[countt].maxx = a[i];
					dp[countt].num = 1;
				}else if(dp[countt].maxx == a[i]){
					dp[countt].num++;
				}
				if(i%mid == 0 && (n-i)>=mid){
					countt++;
					dp[countt].l = i+1;
				}
			}
			// printf("%lld\n",mid);
			// for(long long i=1;i<=countt;i++){
			// 	printf("%lld %lld %lld %lld\n",dp[i].l,dp[i].r,dp[i].maxx,dp[i].num);
			// }
			for(long long i=countt;i>=2;i--){
				while(dp[i].r-dp[i].l+1>mid){
					if(a[dp[i].l] == dp[i].maxx && dp[i].num!=1){
						if(dp[i-1].maxx<dp[i].maxx){
							dp[i-1].maxx = dp[i].maxx;
							dp[i-1].num = 1;
						}else if(dp[i-1].maxx == dp[i].maxx){
							dp[i-1].num++;
						}
						dp[i].l++,dp[i-1].r++;
						dp[i].num--;
						continue;
					}else if(a[dp[i].l]!=dp[i].maxx){
						if(dp[i-1].maxx<a[dp[i].l]){
							dp[i-1].maxx = a[dp[i].l];
							dp[i-1].num = 1;
						}else if(dp[i-1].maxx == a[dp[i].l]){
							dp[i-1].num++;
						}
						dp[i].l++,dp[i-1].r++;
						continue;
					}
					break;
				}
			}
			// printf("%lld\n",mid);
			for(long long i=1;i<=countt;i++){
				sum+=dp[i].maxx;
				// printf("%lld %lld %lld %lld\n",dp[i].l,dp[i].r,dp[i].maxx,dp[i].num);
			}
		}
		if(sum>=m)	l = mid;
		else		r = mid-1;
	}
	printf("%lld\n",l);
	return 0;
}