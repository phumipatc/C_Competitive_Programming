/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
string a;
int mark[30];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,k;
    char c;
    cin >> n >> k >> a;
    a.push_back('?');
    for(int i=1;i<=k;i++){
        cin >> c;
        mark[c-'a'] = 1;
    }
    LL countt = 0,ans = 0;
    for(auto x:a){
        countt++;
        if(isalpha(x) && mark[x-'a'])   continue;
        countt--;
        ans+=(countt*(countt+1))/2;
        countt = 0;
    }
    cout << ans << '\n';
    return 0;
}