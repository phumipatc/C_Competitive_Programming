/*
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
A now;
priority_queue<A > heap;
pair<int ,int > p[1010];
int pa[1010];
int find_root(int i){
    if(pa[i] == i)  return i;
    else            return pa[i] = find_root(pa[i]);
}
int main(){
    int q,n,k,ru,rv;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++)
            scanf("%d %d",&p[i].first,&p[i].second),pa[i] = i;
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
                heap.push({i,j,abs(p[i].first-p[j].first)+abs(p[i].second-p[j].second)});
        n-=k;
        while(n){
            now = heap.top();
            heap.pop();
            ru = find_root(now.u);
            rv = find_root(now.v);
            if(ru == rv)    continue;
            pa[ru] = rv;
            n--;
        }
        while(!heap.empty()){
            now = heap.top();
            heap.pop();
            ru = find_root(now.u);
            rv = find_root(now.v);
            if(ru == rv)    continue;
            printf("%d\n",now.w);
            break;
        }
        while(!heap.empty())    heap.pop();
    }
	return 0;
}
