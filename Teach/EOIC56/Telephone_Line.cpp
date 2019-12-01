/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
pair<int ,int > a[100010];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,m;
    long long ans = 0;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> a[i].first >> a[i].second;
    sort(a,a+n);
    for(int i=1;i<n;i++){
        if(a[i-1].second<=a[i].second)  continue;
        ans+=(a[i-1].second-a[i].second);
    }
    ans+=a[n-1].second;
    cout << ans << '\n';
    return 0;
}