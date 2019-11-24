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
    int l,m,n,now,num,ans;
    cin >> l >> m >> n;
    for(int i=1;i<=n;i++){
        now = l,ans = 1;
        for(int j=1;j<=m;j++){
            cin >> num;
            if(num == 1)    now++;
            else            now--;
            if(now<0 || now>2*l)    ans = 0;
        }
        cout << ans << "\n";
    }
    return 0;
}