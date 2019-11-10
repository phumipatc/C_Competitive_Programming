/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int l,r;
    bool operator<(const A&o)const{
        return l<o.l;
    }
};
A b[200010];
priority_queue<int > heap;
int a[200010];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,pos,k;
    int ans = 0;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=m;i++){
        cin >> pos >> k;
        b[i] = {pos-k,pos+k};
    }
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    int idx = 1;
    for(int i=1;i<=n;i++){
        while(b[idx].l<=a[i] && idx<=m)             heap.push(-b[idx].r),idx++;
        while(!heap.empty() && -heap.top()<a[i])    heap.pop();
        if(!heap.empty())                           ans++,heap.pop();
    }
    cout << ans << endl;
    return 0;
}