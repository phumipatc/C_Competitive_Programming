/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL countt[22];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,num;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> num;
        for(int i=0;i<20;i++){
            if(1<<i & num)
                countt[i]++;
        }
    }
    LL ans = 0;
    for(int i=0;i<20;i++)
        ans+=(1<<i)*(countt[i]*(n-countt[i]));
    cout << ans << '\n';
    return 0;
}