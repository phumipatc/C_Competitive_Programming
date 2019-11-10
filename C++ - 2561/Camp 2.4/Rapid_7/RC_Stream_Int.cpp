/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
priority_queue<A > heap;
int tree[1000010];
void update(int idx,int v){
    while(idx<=1000003){
        tree[idx]+=v;
        idx+= idx & -idx;
    }
}
int query(int idx){
    int sum = 0;
    while(idx>0){
        sum+=tree[idx];
        idx-=idx & -idx;
    }
    return sum;
}
int main(){
    int q,n,opr,u,v,k;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&opr);
            if(opr == 1){
                scanf("%d %d",&u,&v);
                update(u,1);
                heap.push({u,v});
            }else if(opr == 2){
                scanf("%d",&k);
                while(!heap.empty() && heap.top().w<i){
                    update(heap.top().v,-1);
                    heap.pop();
                }
                if(query(1000000)<k){
                    printf("-1\n");
                    continue;
                }
                int l = 1,r = 1e6;
                while(l<r){
                    int mid = (l+r)/2;
                    if(query(mid)<k)    l = mid+1;
                    else                r = mid;
                }
                printf("%d\n",l);
            }
        }
        while(!heap.empty()){
            update(heap.top().v,-1);
            heap.pop();
        }
    }
	return 0;
}
