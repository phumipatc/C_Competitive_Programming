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
    LL n,ans;
    cin >> n;
    ans = (n/374)*12*7;
    n%=374;
    int countt = 0;
    while(n>0){
        n-=23;
        countt++;
        ans+=7;
        if(countt == 12)
            n-=98,countt = 0;
    }
    cout << ans << '\n';
    return 0;
}