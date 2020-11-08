/*
    Author	: Phumipat C. [MAGCARI]
    School	: RYW
    language: C++
    Algo	: Implementing
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int ,int > PII;
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,h,x,ans = 0;
    cin >> n >> h;
    for(int i=1;i<=n;i++){
        cin >> x;
        if(x>h) continue;
        ans = max(ans,x);
    }
    cout << ans << '\n';
    return 0;
}