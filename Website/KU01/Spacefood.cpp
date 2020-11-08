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
    int n,m,k,x,sum = 0,ans = 0;
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        cin >> x;
        sum+=x;
        if(sum>=k)      sum-=k;
        else if(sum>=m) sum = 0,ans++;
        else            ans = -1e9;
    }
    ans = max(ans,-1);
    cout << ans << '\n';
    return 0;
}