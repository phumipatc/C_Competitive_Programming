/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100010];
int main(){
    long long n,m,idx1,idx2,ans = 0;
    cin >> n >> m;
    for(long long i=0;i<n;i++)
        cin >> a[i];
    sort(a,a+n);
    for(long long i=0;i<n;i++){
        idx1 = lower_bound(a+i+1,a+n,m-a[i])-a;
        idx2 = upper_bound(a+i+1,a+n,m-a[i])-a;
        ans+=idx2-idx1;
    }
    cout << ans << endl;
    return 0;
}
