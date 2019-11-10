/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int pos,v;
    bool operator < (const A&o) const{
        return v>o.v;
    }
};
A now;
priority_queue<A > heap;
int a[11010];
int main(){
    int q,n,k,ans,temp;
    scanf("%d",&q);
    while(q--){
        ans = 1e9;
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        heap.push({0,0});
        for(int i=1;i<=n;i++){
            while(!heap.empty() && heap.top().pos<i-k-1)    heap.pop();
            temp = heap.top().v+a[i];
            heap.push({i+k,temp});
        }
        while(!heap.empty()){
            now = heap.top();
            heap.pop();
            if(now.pos>=n)  ans = min(ans,now.v);
        }
        printf("%d\n",ans);
    }
	return 0;
}
