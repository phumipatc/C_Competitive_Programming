/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long LIS[100010];
vector<long long > v[100010];
int main(){
    long long n,maxx = 0,idx,num;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&num);
        idx = upper_bound(LIS,LIS+maxx,num)-LIS;
        if(idx == maxx)	maxx++;
        LIS[idx] = num;
        v[idx].push_back(num);
    }
    printf("%lld ",maxx);
    num = v[maxx-1][0],idx = 0;
    long long ans = num,maxxx;
    for(long long i=maxx-2;i>=0;i--){
		maxxx = 0;
        for(auto x:v[i]){
            if(x<=num){
                maxxx = max(maxxx,x);
            }
        }
		num = maxxx;
		ans+=maxxx;
    }
    printf("%lld\n",ans);
	return 0;
}
