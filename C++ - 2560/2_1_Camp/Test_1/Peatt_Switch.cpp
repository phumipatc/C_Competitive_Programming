/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100];
int main()
{
    int n,ans=0,minn=1e9,idx;
    cin >> n;
    for(int i=0;i<n;i++)   cin >> a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++){
        idx=upper_bound(a,a+n,2*(a[i]))-a;
        ans=i+(n-idx);
        minn=min(ans,minn);
//        printf("%d %d\n",ans,minn);
    }
    cout << minn;
    return 0;
}
