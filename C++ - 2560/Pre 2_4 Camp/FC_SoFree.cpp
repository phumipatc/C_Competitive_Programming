/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long a[2005],dp[2048],temp[2048];
int main(){
    long long n,k;
    cin >> n;
    for(long long i=1;i<=n;i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    dp[0]=1;
    for(long long i=1;i<=n;i++){
        long long countt=1;
        memset(temp,0,sizeof temp);
        while(a[i]==a[i+1] && i+1<n)   countt++,i++;
        for(long long j=0;j<2048;j++)
            temp[a[i]^j]+=dp[j]*countt;
        for(long long j=0;j<2048;j++){
            dp[j]+=temp[j];
            dp[j]%=MOD;
        }
    }
    cin >> k;
    cout << dp[k]%MOD << endl;
    return 0;
}
