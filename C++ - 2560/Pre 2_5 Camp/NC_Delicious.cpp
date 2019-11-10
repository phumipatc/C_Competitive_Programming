/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long qs[100100],LIS[100100];
int main(){
    long long idx,n,maxx=0;
    cin >> n;
    for(long long i=1;i<=n;i++){
        cin >> qs[i];
        qs[i]+=qs[i-1];
        if(qs[i]<0) continue;
        idx = lower_bound(LIS,LIS+maxx,qs[i])-LIS;
        if(idx == maxx)   maxx++;
        LIS[idx] = qs[i];
    }
    cout << idx+1 << endl;
    return 0;
}
