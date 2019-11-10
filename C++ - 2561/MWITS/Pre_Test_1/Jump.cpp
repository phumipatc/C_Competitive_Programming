/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[30010];
int main(){
    int n,k,idx,ans = 0;
    cin >> n >> k;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++){
        idx = upper_bound(a+1,a+n+1,a[i]+k)-a-1;
        ans = max(ans,idx-i);
    }
    printf("%d\n",ans);
	return 0;
}
