/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long u,v,w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
priority_queue< A> heap;
struct B{
    long long x,y;
};
B a[1005];
long long p[1005];
long long find_root(long long idx){
    if(p[idx] == idx)   return idx;
    else                return p[idx] = find_root(p[idx]);
}
int main(){
    long long q,n,k,ru,rv,temp;
    cin >> q;
    while(q--){
        cin >> n >> k;
        temp=n-k;
        for(long long i=1;i<=n;i++){
            cin >> a[i].x >> a[i].y;
            p[i] = i;
        }
        for(long long i=1;i<n;i++)
            for(long long j=i+1;j<=n;j++)
                heap.push({i,j,abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y)});
        while(temp){
            now = heap.top();
            heap.pop();
            ru = find_root(now.u);
            rv = find_root(now.v);
            if(ru != rv){
                p[ru]=rv;
                temp--;
            }
        }
        while(!heap.empty()){
            now = heap.top();
            heap.pop();
            ru = find_root(now.u);
            rv = find_root(now.v);
            if(ru != rv){
                cout << now.w << endl;
                break;
            }
        }
        while(!heap.empty())    heap.pop();
    }
    return 0;
}
