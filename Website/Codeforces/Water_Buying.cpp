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
    long long q,n,a,b;
    cin >> q;
    while(q--){
        cin >> n >> a >> b;
        if(a*2<=b)
            cout << a*n << "\n";
        else
            cout << ((n/2)*b)+((n%2)*a) << "\n";
    }
    return 0;
}