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
    int q,hr,mi,ans;
    cin >> q;
    while(q--){
        cin >> hr >> mi;
        ans = (60-mi)%60;
        if(mi)  hr++;
        ans+=((24-hr)%24)*60;
        cout << ans << '\n';
    }
    return 0;
}