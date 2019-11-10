/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[300005],l[300005],r[300005];
int main(){
    int q,n;
    cin >> q;
    while(q--){
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            a[i+n] = a[i+(2*n)] = a[i];
        }
        for(int i=1;i<=(3*n);i++){
            l[i]=i-1;
            while(l[i]>0 && a[i]>=a[l[i]])  l[i] = l[l[i]];
        }
        for(int i=(3*n);i>0;i--){
            r[i]=i+1;
            while(r[i]<=(3*n) && a[i]>=a[r[i]]) r[i] = r[r[i]];
        }
        for(int i=1;i<=(3*n);i++)
            l[i] = i-l[i]-1;
        for(int i=(3*n);i>0;i--)
            r[i] = r[i]-i-1;
        for(int i=n+1;i<=(2*n);i++){
            int ans = min(l[i],r[i]);
            if(ans >= (n-1)/2)  cout << (n-1)/2 << " ";
            else                cout << ans << " ";
        }
    }
    return 0;
}
