/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<LL > base3;
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    LL q,n,last;
    cin >> q;
    while(q--){
        cin >> n;
        while(n){
            base3.push_back(n%3);
            n/=3;
        }
        last = base3.size();
        for(int i=base3.size()-1;i>=0;i--){
            if(base3[i] == 0)   last = i;
            if(base3[i] == 2){
                if(last == base3.size()){
                    for(int j=0;j<base3.size();j++)
                        base3[j] = 0;
                    base3.push_back(1);
                }else{
                    base3[last] = 1;
                    for(int j=0;j<last;j++)
                        base3[j] = 0;
                }
                break;
            }
        }
        LL ans = 0;
        reverse(base3.begin(),base3.end());
        for(auto x:base3){
            ans*=3;
            ans+=x;
        }
        cout << ans << "\n";
        base3.clear();
    }
    return 0;
}