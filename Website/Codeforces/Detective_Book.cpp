/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[10010];
int main(){
    int n,ans = 0,temp;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i] = max(a[i],a[i-1]);
        if(a[i] == i)   ans++;
    }
    cout << ans << endl;
	return 0;
}
