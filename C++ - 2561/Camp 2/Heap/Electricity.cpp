/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,id;
    bool operator < (const A&o) const{
        if(v!=o.v)  return v>o.v;
        else        return id<o.id;
    }
};
A now;
priority_queue<A > heap;
int main(){
    int n,k,temp;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&temp);
        if(heap.empty()){
            heap.push({temp,i});
            continue;
        }
        while(!heap.empty() && heap.top().id<i-k)   heap.pop();
        heap.push({temp+heap.top().v,i});
    }
    while(!heap.empty() && heap.top().id!=n)    heap.pop();
    printf("%d\n",heap.top().v);
	return 0;
}
