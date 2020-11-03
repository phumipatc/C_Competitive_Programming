/*
    Author  : Phumipat C. [MAGCARI]
    School	: RYW
    Langauge: C++
    Algo	: Implementing
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int maxx[22];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,m,s,x,ans = 0;
    cin >> n >> m >> s;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> x;
            x+=s*i;
            ans+= x>maxx[j];
            maxx[j] = max(maxx[j],x);
        }
    }
    cout << ans << '\n';
}