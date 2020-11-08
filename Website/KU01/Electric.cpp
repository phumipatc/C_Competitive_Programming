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
    int n,m,last,now,minn = 1e9,maxx;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        last = maxx = 0;
        for(int j=1;j<=m;j++){
            cin >> now;
            maxx = max(maxx,now-last);
            last = now;
        }
        minn = min(minn,maxx);
    }
    cout << minn << '\n';
    return 0;
}