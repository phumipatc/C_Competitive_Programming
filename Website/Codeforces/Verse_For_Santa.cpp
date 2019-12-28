/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[100010];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    LL q,n,k,maxx,idx,ans;
    cin >> q;
    while(q--){
        cin >> n >> k;
        maxx = ans = 0;
        for(LL i=1;i<=n;i++){
            cin >> a[i];
            a[i]+=a[i-1];
            if(a[i]>k)  continue;
            maxx = i;
        }
        for(LL i=1;i<=n;i++){
            if(a[i-1]>k)    break;
            idx = upper_bound(a+i+1,a+n+1,a[i]+(k-a[i-1]))-a-1;
            // printf("%d\n",idx);
            if(idx-1>maxx){
                maxx = idx-1;
                ans = i;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}