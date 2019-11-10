/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[2010],b[2010];
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++)
        cin >> b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    int ans = 0;
    for(int i=1;i<=n;i++)
        ans+=abs(b[i]-a[i]);
    printf("%d\n",ans);
	return 0;
}
