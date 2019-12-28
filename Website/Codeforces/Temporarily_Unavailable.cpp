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
    int q,a,b,c,r,ans;
    cin >> q;
    while(q--){
        cin >> a >> b >> c >> r;
        if(b<a) swap(a,b);
        if(c-r>=b || c+r<=a){
            cout << b-a << '\n';
            continue;
        }
        if(c+r>=b && c-r<=a){
            cout << "0\n";
            continue;
        }
        ans = b-a;
        if(c-r<b && c-r>=a){
            ans-=min(b,c+r)-(c-r);
        }else if(c+r>a && c+r<=b){
            ans-=(c+r)-max(a,c-r);
        }
        cout << ans << '\n';
    }
    return 0;
}