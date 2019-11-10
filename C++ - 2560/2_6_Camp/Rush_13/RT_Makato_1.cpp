/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
    int n,q,l,r,ans;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i]^=a[i-1];
    }
    while(q--){
        cin >> l >> r;
        ans = a[l-1]^a[r];
        cout << ans << endl;
    }
    return 0;
}
