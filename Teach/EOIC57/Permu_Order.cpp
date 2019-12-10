/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[1010],fact[1010];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    LL n,m,MOD,ans;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    fact[0] = fact[1] = 1;
    while(m--){
        cin >> MOD;
        for(int i=2;i<=n;i++)
            fact[i] = (fact[i-1]*i)%MOD;
        ans = 0;
        for(int i=1;i<n;i++){
            LL num = 0;
            for(int j=1;j<i;j++){
                if(a[j]>a[i])   continue;
                num++;
            }
            num = a[i]-num;
            ans+=((num-1)*fact[n-i])%MOD;
            ans%=MOD;
        }
        ans++;
        ans%=MOD;
        cout << ans << "\n";
    }
    return 0;
}