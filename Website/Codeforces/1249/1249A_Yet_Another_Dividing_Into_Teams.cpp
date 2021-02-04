/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[110];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int q,n,ans;
    cin >> q;
    while(q--){
        cin >> n;
        ans = 1;
        for(int i=1;i<=n;i++)
            cin >> a[i];
        sort(a+1,a+n+1);
        for(int i=1;i<n;i++){
            if(a[i]+1 == a[i+1]){
                ans = 2;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}