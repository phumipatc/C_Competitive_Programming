/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long pos,v;
    bool operator < (const A&o) const{
        return pos<o.pos;
    }
};
A a[100005];
deque< A> deq;
long long dp[100005];
int main(){
    long long n,k,ans = 0;
    cin >> n >> k;
    for(long long i=1;i<=n;i++)
        cin >> a[i].pos >> a[i].v;
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++){
        while(!deq.empty() && a[i].pos-deq.front().pos>k)           deq.pop_front();
        if(!deq.empty())    dp[i] = max(dp[i-1],a[i].v-a[i].pos+deq.front().v);
        else                dp[i] = dp[i-1];
        while(!deq.empty() && a[i].v+a[i].pos+dp[i-1]>deq.back().v) deq.pop_back();
        deq.push_back({a[i].pos,a[i].v+a[i].pos+dp[i-1]});
    }
    cout << dp[n] << endl;
    return 0;
}
