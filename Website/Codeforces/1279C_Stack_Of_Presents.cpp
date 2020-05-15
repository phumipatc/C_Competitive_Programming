/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[100010],num[100010],b[100010];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    LL q,n,m,k;
    cin >> q;
    while(q--){
        cin >> n >> m;
        for(LL i=0;i<n;i++){
            cin >> a[i];
            num[a[i]] = i;
        }
        for(LL i=0;i<m;i++)
            cin >> b[i];
        LL maxx = num[b[0]],ans = 2*num[b[0]]+1;
        for(LL i=1;i<m;i++){
            if(num[b[i]]<maxx)  ans++;
            else                ans+=2*(num[b[i]]-i)+1,maxx = num[b[i]];
        }
        cout << ans << '\n';
    }
    return 0;
}