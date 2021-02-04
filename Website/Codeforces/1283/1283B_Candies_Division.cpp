/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int q,ans,n,k;
    cin >> q;
    while(q--){
        cin >> n >> k;
        ans = (n/k)*k;
        n%=k;
        ans+=min(n,k/2);
        cout << ans << '\n';
    }
    return 0;
}