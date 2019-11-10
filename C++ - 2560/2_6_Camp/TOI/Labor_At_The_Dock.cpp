/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main(){
    long long m,n;
    cin >> m >> n;
    for(long long i=1;i<=m;i++)
        cin >> a[i];
    long long l = 0,r = 1e18;
    while(l<r){
        long long mid = (l+r)/2,countt = 0;
        for(long long i=1;i<=m;i++)
            countt+=(mid/a[i]);
        if(countt<n)    l = mid+1;
        else            r = mid;
    }
    cout << l << endl;
    return 0;
}
