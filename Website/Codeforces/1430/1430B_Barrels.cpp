/*
    Author	: Phumipat C.
    School	: RYW
    language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[200010];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int q,n,k;
    cin >> q;
    while(q--){
        cin >> n >> k;
        for(int i=1;i<=n;i++)
            cin >> a[i];
        sort(a+1,a+n+1);
        for(int i=1;i<=k;i++){
            a[n]+=a[n-i];
            a[n-i] = 0;
        }
        sort(a+1,a+n+1);
        cout << a[n]-a[1] << '\n';
    }
}