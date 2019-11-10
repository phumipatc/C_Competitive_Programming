/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long need[100005],have[100005];
int main(){
    long long n,m;
    cin >> n;
    for(long long i=1;i<=n;i++)
        cin >> need[i];
    for(long long i=1;i<=n;i++)
        cin >> have[i];
    cin >> m;
    long long l = 0,r = 2000000;
    while(l<r){
        long long mid = (l+r+1)/2,countt = 0;
        for(long long i=1;i<=n;i++)
            countt+=max((need[i]*mid)-have[i],0ll);
        if(countt>m)    r = mid-1;
        else            l = mid;
    }
    cout << l << endl;
    return 0;
}
