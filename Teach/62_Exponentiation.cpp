/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > num;
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0);
    int a,n,temp,q;
    cin >> q;
    while(q--){
        cin >> a >> n;
        num.push_back(1);
        for(int i=1;i<=n;i++){
            temp = 0;
            for(int j=0;j<num.size();j++){
                temp+=num[j]*a;
                num[j] = temp%10;
                temp/=10;
            }
            while(temp){
                num.push_back(temp%10);
                temp/=10;
            }
        }
        reverse(num.begin(),num.end());
        for(auto x:num)
            cout << x;
        num.clear();
    }
    return 0;
}