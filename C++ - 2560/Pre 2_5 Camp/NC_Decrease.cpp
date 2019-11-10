/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[100100][2],a[100100];
int main(){
    int q,n;
    cin >> q;
    while(q--){
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            if(i == 1)  continue;
            dp[i][0]=max(dp[i-1][0]+abs(a[i]-a[i-1]),dp[i-1][1]+abs(a[i]-1));
            dp[i][1]=max(dp[i-1][0]+abs(a[i-1]-1),dp[i-1][1]);
        }
        cout << max(dp[n][0],dp[n][1]);
    }
    return 0;
}
