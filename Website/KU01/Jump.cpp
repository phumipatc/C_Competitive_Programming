/*
    Author	: Phumipat C. [MAGCARI]
    School	: RYW
    Langauge: C++
    Algo	: Implementing
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int ,int > PII;
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,minn;
    char c;
    cin >> n;
    minn = n;
    for(int i=1;i<=n;i++){
        cin >> c;
        if(c == '.')    continue;
        minn = min(minn,max(i-1,n-i));
    }
    cout << minn << '\n';
}