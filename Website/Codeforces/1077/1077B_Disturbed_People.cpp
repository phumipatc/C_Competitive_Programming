/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
    int n,countt = 0;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=2;i<n;i++){
        if(a[i])    continue;
        if(a[i-1] && a[i+1]){
            a[i+1]^=1;
            countt++;
        }
    }
    printf("%d\n",countt);
    return 0;
}