/*
    Author  : Phumipat C. [MAGCARI]
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
    int n,ans = 0,x,y;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> x >> y;
        if(x>400)           continue;
        if(y<150 || y>200)  continue;
        ans++;
    }
    cout << ans << '\n';
}