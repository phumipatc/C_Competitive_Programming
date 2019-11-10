/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 999999999
using namespace std;
long long tree[45][80100],a[80100];
void update(long long n,long long idx,long long v){
    while(idx<=80000){
        tree[n][idx]+=v;
        idx+=(idx&(-idx));
    }
}
long long query(long long n,long long idx){
    long long sum = 0;
    while(idx>0){
        sum+=tree[n][idx];
        idx-=(idx&(-idx));
    }
    return sum;
}
int main(){
    long long n,k,v,ans = 0;
    cin >> n >> k;
    for(long long i=1;i<=n;i++)
        cin >> a[i];
    for(long long i=n;i>=1;i--){
        update(1,a[i],1);
        for(long long j=2;j<=k;j++){
            v = query(j-1,a[i]-1)%MOD;
            update(j,a[i],v);
            if(j == k){
                ans+=v;
                ans%=MOD;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
