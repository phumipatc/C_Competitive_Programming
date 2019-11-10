/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
    int n,k,countt = 0;
    cin >> n >> k;
    for(int i=2;i<=n;i++){
        if(!a[i]){
            a[i] = 1;
            countt++;
            if(countt == k){
                cout << i << endl;
                return 0;
            }
            for(int j=i*2;j<=n;j+=i){
                if(a[j])    continue;
                countt++;
                a[j] = 1;
                if(countt == k){
                    cout << j << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
