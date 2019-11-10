/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[201];
int main(){
    int n,m,ans = 1e9;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=m;i++)
        cin >> a[i+n];
    for(int i=1;i<n+m;i++){
        for(int j=i+1;j<=n+m;j++){
            if(i<=n && j>n)
                ans = min(ans,a[i]+a[j]+100);
            else
                ans = min(ans,a[i]+a[j]);
        }
    }
    cout << ans << endl;
    return 0;
}
