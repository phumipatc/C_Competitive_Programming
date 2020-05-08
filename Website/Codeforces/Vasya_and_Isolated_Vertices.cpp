/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,idx;
    cin >> n >> m;
    cout << max(0,n-(2*m));
    while(m>0){
        idx = 1;
        while(m-idx>=0){
            m-=idx;
            idx++;
        }
        if(idx == 2){
            n--;
            continue;
        }
        n-=idx;
    }
    cout << " " << n;
    return 0;
}
