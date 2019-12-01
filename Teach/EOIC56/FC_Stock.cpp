/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[1000010],b[100010];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=2;i<=n;i++)
        b[i] = max(a[i]-a[i-1],0ll)+b[i-1];
    int q,l,r;
    cin >> q;
    while(q--){
        cin >> l >> r;
        cout << b[r]-b[l] << "\n";
    }
    return 0;
}