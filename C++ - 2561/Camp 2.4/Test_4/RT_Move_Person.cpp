/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
map<int ,int > mapp;
int a[5010],b[5010],LIS[5010];
int main(){
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b+1,b+n+1);
    int idx = 1,maxx = 0;
    for(int i=1;i<=n;i++){
        mapp[b[i]] = idx;
        if(i%k == 0)    idx++;
    }
    for(int i=1;i<=n;i++){
        idx = upper_bound(LIS,LIS+maxx,mapp[a[i]])-LIS;
        if(idx == maxx) maxx++;
        LIS[idx] = mapp[a[i]];
    }
    cout << n-maxx << endl;
    return 0;
}
