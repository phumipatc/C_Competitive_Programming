/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000005],l[1000005],r[1000005];
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++){
        l[i] = i-1;
        while(l[i]>0 && a[l[i]]<=a[i])  l[i] = l[l[i]];
    }
    for(int i=n;i>=1;i--){
        r[i] = i+1;
        while(r[i]<n+1 && a[r[i]]<=a[i])    r[i] = r[r[i]];
    }
    for(int i=1;i<=n;i++){
        cout << r[i]-l[i]-1 << " ";
    }
    return 0;
}
