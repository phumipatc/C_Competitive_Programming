/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long idx,more;
    bool operator < (const A&o) const{
        if(more!=o.more)    return more<o.more;
        else                return idx>o.idx;
    }
};
struct B{
    long long idx,v;
    bool operator < (const B&o) const{
        return idx<o.idx;
    }
};
B ans[100005];
priority_queue< A> heap;
int main(){
    long long n,k,a,b,can,now=1,sum=0;
    cin >> n >> k;
    for(long long i=1;i<=n;i++){
        cin >> a >> b;
        if(a>=b)    can=0;
        else        can=min(a,b-a);
        sum+=min(a,b);
        heap.push({i,can});
    }
    while(!heap.empty() && k--){
        ans[now].idx=heap.top().idx;
        ans[now].v=heap.top().more;
        sum+=ans[now].v;
        heap.pop();
        now++;
    }
    sort(ans+1,ans+now);
    for(long long i=1;i<now;i++){
        cout << ans[i].idx << " ";
    }
    cout << endl << sum;
    return 0;
}
