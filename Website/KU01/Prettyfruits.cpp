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
    int n,sum = 0,x,y;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> x >> y;
        if((double )y/x*100<=75)    sum+=5;
        else                        sum+=3;
    }
    cout << sum << '\n';
    return 0;
}