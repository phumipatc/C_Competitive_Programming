/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
pair<int ,int > a[1005];
priority_queue< A> heap;
priority_queue<int ,greater<int > > ans;
int p[1005];
int find_root(int idx){
    if(p[idx]==idx) return idx;
    return p[idx]=find_root(p[idx]);
}
int main(){
    int q,n,k,ru,rv;
    cin >> q;
    while(q--){
        cin >> n >> k;
        for(int i=1;i<=n;i++)
            cin >> a[i].first >> a[i].second;
        for(int i=1;i<=n;i++)
            p[i]=i;
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
                heap.push({i,j,abs(a[i].first-a[j].first)+abs(a[i].second-a[j].second)});
        while(!heap.empty()){
            A now=heap.top();
            heap.pop();
            ru=find_root(now.u);
            rv=find_root(now.v);
            if(ru!=rv)
                p[ru]=rv;
            else
                ans.push(now.w);
        }
        printf("%d\n",ans.top());
    }
    return 0;
}
