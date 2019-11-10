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
    int q,a,b,n,S;
    cin >> q;
    while(q--){
        cin >> a >> b >> n >> S;
        S-=n*min(S/n,a);
        S-=b;
        if(S>0) cout << "NO\n";
        else    cout << "YES\n";
    }
    return 0;
}