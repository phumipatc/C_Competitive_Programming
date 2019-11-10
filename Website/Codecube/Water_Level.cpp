/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000010],l[1000010],r[1000010];
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++)
        l[i] = max(a[i],l[i-1]);
    for(int i=n;i>=1;i--)
        r[i] = max(a[i],r[i+1]);
    for(int i=1;i<n;i++)
        cout << min(l[i],r[i+1]) << ' ';
    return 0;
}
