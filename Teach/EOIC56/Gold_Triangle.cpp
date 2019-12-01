/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
long long x[100100],y[100100];
pair<long long ,long long > p[100100];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    long long n,i,ans = 0;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> p[i].first >> p[i].second;
        x[p[i].first]++;
        y[p[i].second]++;
    }
    for(i=0;i<n;i++)
        ans+=(x[p[i].first]-1) * (y[p[i].second]-1);
    printf("%lld\n",ans);
    return 0;
}