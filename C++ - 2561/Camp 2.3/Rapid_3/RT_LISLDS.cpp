/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int q,n,k;
    cin >> q;
    while(q--){
        cin >> n >> k;
        if(k>=sqrt(n))  cout << "Yes" << endl;
        else            cout << "No" << endl;
    }
    return 0;
}
