/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
string ans;
int main(){
    int n;
    cin >> n;
    n++;
    while(n>1){
        if(n&1) ans.push_back('7');
        else    ans.push_back('4');
        n/=2;
    }
    reverse(ans.begin(),ans.end());
    cout << ans;
    return 0;
}
