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
    int a,b,c;
    cin >> a >> b >> c;
    cout << a+b+c-__gcd(a,b)-__gcd(a,c)-__gcd(b,c)+__gcd(a,__gcd(b,c));
    return 0;
}