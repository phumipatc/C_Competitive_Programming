/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100005],l[100005],r[100005];
int main(){
    long long q,n,maxx;
    cin >> q;
    while(q--){
        maxx=-1;
        cin >> n;
        for(long long i=1;i<=n;i++)
            cin >> a[i];
        for(long long i=1;i<=n;i++){
            l[i]=i-1;
            while(l[i]>0 && a[i]<=a[l[i]])  l[i]=l[l[i]];
        }
        for(long long i=n;i>0;i--){
            r[i]=i+1;
            while(r[i]<=n && a[i]<=a[r[i]]) r[i]=r[r[i]];
        }
        for(long long i=1;i<=n;i++)
            maxx=max(maxx,(r[i]-l[i]-1)*a[i]);
        cout << maxx << endl;
    }
    return 0;
}
