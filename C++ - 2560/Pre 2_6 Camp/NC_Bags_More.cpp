/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long w,v;
    bool operator < (const A&o) const{
        if(v!=o.v)  return v>o.v;
        else        return w<o.w;
    }
};
A a[300905];
set<long long > sett;
set<long long > ::iterator idx;
long long countt[1000005];
int main(){
    long long n,m,ans = 0,num;
    cin >> n >> m;
    for(long long i=1;i<=n;i++)
        cin >> a[i].w >> a[i].v;
    sort(a+1,a+n+1);
    for(long long i=1;i<=m;i++){
        cin >> num;
        countt[min(num,1000000ll)]++;
        sett.insert(min(num,1000000ll));
    }
    sett.insert(1e18);
    for(long long i=1;i<=n;i++){
        idx = sett.lower_bound(a[i].w);
        if((*idx) == 1e18)  continue;
        ans+=a[i].v;
        countt[(*idx)]--;
        if(countt[(*idx)]==0)
            sett.erase(idx);
    }
    cout << ans << endl;
    return 0;
}
