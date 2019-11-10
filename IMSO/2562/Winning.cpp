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
    int n,m,p;
    while(1){
        cin >> n;
        if(n == 0)  break;
        cin >> m >> p;
        if(n == m){
            cout << "yes\n";
            continue;
        }
        n-=m;
        for(int i=p;i<=m;i+=p)
            n-=p;
        if(n<0){
            cout << "yes\n";
            continue;
        }
        cout << "no\n";
    }
    return 0;
}