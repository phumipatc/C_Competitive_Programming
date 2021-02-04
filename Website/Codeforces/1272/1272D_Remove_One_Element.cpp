/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[200010],l[200010],r[200010];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++){
        l[i] = 1;
        if(a[i]>a[i-1])
            l[i]+=l[i-1]; 
    }
    for(int i=n;i>=1;i--){
        r[i] = 1;
        if(a[i]<a[i+1]) r[i]+=r[i+1];
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans,l[i]+r[i]-1);
        if(a[i+1]>a[i-1])   ans = max(ans,l[i-1]+r[i+1]);
    }
    cout << ans << '\n';
    return 0;
}