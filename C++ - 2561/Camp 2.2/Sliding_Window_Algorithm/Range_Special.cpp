/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long idx,v;
};
deque<A > minn,maxx;
long long a[1000010];
int main(){
    long long n,p,q,last = 0,ans = 0;
    cin >> n >> p >> q;
    for(long long i=1;i<=n;i++)
        cin >> a[i];
    for(long long i=1;i<=n;i++){
        while(!minn.empty() && a[i]<minn.back().v)    minn.pop_back();
        while(!maxx.empty() && a[i]>maxx.back().v)    maxx.pop_back();
        minn.push_back({i,a[i]});
        maxx.push_back({i,a[i]});
        while(!minn.empty() && !maxx.empty()){
            if(maxx.front().v-minn.front().v<=q)    break;
            if(maxx.front().idx<minn.front().idx)   last = maxx.front().idx,maxx.pop_front();
            else                                    last = minn.front().idx,minn.pop_front();
        }
        ans+=(i-last);
    }
    last = 0;
    while(!minn.empty())    minn.pop_back();
    while(!maxx.empty())    maxx.pop_back();
    for(long long i=1;i<=n;i++){
        while(!minn.empty() && a[i]<minn.back().v)    minn.pop_back();
        while(!maxx.empty() && a[i]>maxx.back().v)    maxx.pop_back();
        minn.push_back({i,a[i]});
        maxx.push_back({i,a[i]});
        while(!minn.empty() && !maxx.empty()){
            if(maxx.front().v-minn.front().v<p)     break;
            if(maxx.front().idx<minn.front().idx)   last = maxx.front().idx,maxx.pop_front();
            else                                    last = minn.front().idx,minn.pop_front();
        }
        ans-=(i-last);
    }
    cout << ans << endl;
    return 0;
}
