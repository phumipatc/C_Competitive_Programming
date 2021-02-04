/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[65010];
int main(){
    int n,ans = 0;
    cin >> n >> a+1;
    for(int i=1;i<=n;i++){
        if((a[i]-'0')%2)    continue;
        ans+=i;
    }
    cout << ans << endl;
	return 0;
}
