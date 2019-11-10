/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long idx,val;
    bool operator < (const A&o) const{
        return val<o.val;
    }
};
priority_queue< A> heap;
long long qs[500005],dp[500005];
int main(){
    long long n,k;
    cin >> n >> k;
    heap.push({0,0});
    for(long long i=1;i<=n;i++){
        cin >> qs[i];
        qs[i]+=qs[i-1];
        while(!heap.empty() && qs[i]-qs[heap.top().idx]>k)  heap.pop();
        if(qs[i]-qs[i-1]>k) dp[i]=dp[i-1];
        else                dp[i]=max(dp[i-1],qs[i]+heap.top().val);
        heap.push({i,-qs[i]+dp[i-1]});
    }
    cout << dp[n];
    return 0;
}
