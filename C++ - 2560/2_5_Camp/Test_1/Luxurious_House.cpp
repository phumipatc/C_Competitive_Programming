/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long a,b;
    bool operator < (const A&o) const{
        if(a!=o.a)      return a<o.a;
        else if(b!=o.b) return b>o.b;
        else            return b<o.b;
    }
};
A house[100005];
priority_queue<long long > heap;
int main(){
    long long n,ans=0,countt=0;
    cin >> n;
    for(long long i=1;i<=n;i++)
        cin >> house[i].a >> house[i].b;
    sort(house+1,house+n+1);
    for(long long i=1;i<=n;i++){
        if(heap.size()<house[i].a)
            heap.push({-house[i].b});
        else if(-heap.top()<house[i].b){
            heap.pop();
            heap.push({-house[i].b});
        }
    }
    while(!heap.empty()){
        ans-=heap.top();
        countt++;
        heap.pop();
    }
    cout << ans << endl << countt << endl;
    return 0;
}
