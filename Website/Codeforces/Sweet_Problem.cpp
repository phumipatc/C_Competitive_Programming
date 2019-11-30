/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,r,g,b,ans = 0;
    int a[5];
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int i=1;i<=3;i++)
            cin >> a[i];
        sort(a+1,a+4);
        ans = 0;
        int temp = a[3]-a[2];
        if(temp<=a[1]){
            ans+=temp;
            a[3]-=temp;
            a[1]-=temp;
        }else{
            ans+=a[1];
            a[3]-=a[1];
            a[1] = 0;
        }
        ans+=a[1];
        a[2]-=a[1]/2;
        a[3]-=a[1]/2;
        a[3]-=a[1]%2;
        ans+=min(a[2],a[3]);
        cout << ans << "\n";
    }
    return 0;
}