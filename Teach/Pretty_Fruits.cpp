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
    int q,l,w,ans = 0;
    cin >> q;
    while(q--){
        cin >> l >> w;
        if(w<=(75.0*l)/100) ans+=5;
        else                ans+=3;
    }
    cout << ans << endl;
    return 0;
}