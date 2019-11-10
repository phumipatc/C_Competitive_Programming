/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[12],b[12];
int main(){
    int n,sweet,salt,ans = 1e9;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i] >> b[i];
    for(int i=1;i<(1<<n);i++){
        sweet = 1,salt = 0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                sweet*=a[j],salt+=b[j];
            }
        }
        ans = min(ans,abs(sweet-salt));
    }
    cout << ans << endl;
	return 0;
}
