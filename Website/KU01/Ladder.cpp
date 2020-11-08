/*
    Author	: Phumipat C.
    School	: RYW
    language: C++
    Algo	: Implementing
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[1010];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,m,x,now = 0;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    while(m--){
        cin >> x;
        if(now == n)    continue;
        now+=x;
        now = max(now,0);
        now = min(now,n);
        now+=a[now];
        now = max(now,0);
        now = min(now,n);
    }
    cout << now << '\n';
}