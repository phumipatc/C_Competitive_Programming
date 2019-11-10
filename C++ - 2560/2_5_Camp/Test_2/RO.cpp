/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long v,idx;
    bool operator < (const A&o) const{
        if(v!=o.v)  return v<o.v;
        else        return idx<o.idx;
    }
};
A a[1000005];
char str;
long long dp[1000005],arr[1000005];
int main(){
    long long n,k,idx,ans=0;
    cin >> n >> k;
    for(long long i=1;i<=n;i++){
        cin >> str;
        if(str=='R')        dp[i]-=k;
        else if(str=='O')   dp[i]++;
        dp[i]+=dp[i-1];
        a[i]={dp[i],i};
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++)
        arr[i] = a[i].v;
    for(long long i=1;i<n;i++){
        if(a[i].v == a[i+1].v){
            idx = upper_bound(arr,arr+n+1,arr[i])-arr;
            ans = max(ans,a[idx-1].idx-a[i].idx);
            i = idx-1;
        }
    }
    cout << ans << endl;
    return 0;
}
