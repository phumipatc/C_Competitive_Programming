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
    int n,m,now = 0,num,ans;
    char opr,dir;
    cin >> n >> m;
    while(m--){
        cin >> opr >> dir >> num;
        if(dir == 'B')  num*=-1;
        if(opr == 'Q'){
            ans = now+num;
            ans%=n; ans+=n; ans%=n;
            cout << ans+1 << "\n";
        }else{
            now+=num;
            now%=n; now+=n; now%=n;
        }
    }
    return 0;
}