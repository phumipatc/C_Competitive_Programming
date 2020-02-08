/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
map<long long ,long long > mapp;
int main(){
    long long q,n,num,sum,ans;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        ans = sum = 0;
        mapp[0] = 1;
        for(long long i=1;i<=n;i++){
            scanf("%lld",&num);
            sum+=num;
            ans+=mapp[sum];
            mapp[sum]++;
        }
        printf("%lld\n",ans);
        mapp.clear();
    }
	return 0;
}