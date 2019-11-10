/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[200010],ans[200010],countt[200010];
int main(){
    long long n,minn = 0;
    cin >> n;
    for(long long i=2;i<=n;i++)
        cin >> a[i];
    for(long long i=2;i<=n;i++){
        ans[i] = ans[i-1]+a[i];
        minn = min(minn,ans[i]);
    }
    for(long long i=1;i<=n;i++){
        if(ans[i]-minn+1>n){
            cout << "-1" << endl;
            return 0;
        }
        countt[ans[i]-minn+1]++;
    }
    for(long long i=1;i<=n;i++){
        if(countt[i]!=1){
            cout << "-1" << endl;
            return 0;
        }
    }
    for(long long i=1;i<=n;i++){
        cout << ans[i]-minn+1 << " ";
    }
	return 0;
}
