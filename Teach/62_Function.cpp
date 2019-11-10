/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
bool mark[1000010];
vector<LL > prime;
int main(){
    // ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    // freopen("10.in","r",stdin);
    LL q,l,r;
    prime.push_back(2);
    for(LL i=3;i<=1000000;i+=2)
        mark[i] = true;
    for(LL i=3;i<=sqrt(1000000);i+=2){
        if(!mark[i])    continue;
        for(LL j=i*i;j<=1000000;j+=i)
            mark[j] = false;
    }
    for(LL i=3;i<=1000000;i+=2){
        if(!mark[i])    continue;
        prime.push_back(i);
    }
    LL ans,num;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld",&l,&r);
        ans = 0;
        for(auto x:prime){
            if(x>r) break;
            num = (r/x)-((l-1)/x);
            ans+=num;
            ans+=num*(num-1)/2;
        }
        printf("%lld\n",ans);
    }
    return 0;
}