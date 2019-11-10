/*
    Task    :
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
int tree[100100];
int p[200100];
priority_queue< A> heap;
void update(int idx,int v){
    while(idx<=100000){
        tree[idx]+=v;
        idx+=(idx&(-idx));
    }
}
int query(int idx){
    int sum = 0;
    while(idx>0){
        sum+=tree[idx];
        idx-=(idx&(-idx));
    }
    return sum;
}
int main(){
    int m,opr,v,idx = 1;
    scanf("%d",&m);
    while(m--){
        scanf("%d",&opr);
        if(opr == 1){
            scanf("%d",&v);
            update(v,1);
            heap.push({idx,v});
            p[idx++] = v;
        }else if(opr == 2){
            if(heap.empty()){
                printf("0\n");
                continue;
            }
            printf("%d\n",heap.top().v);
            update(heap.top().w,-1);
            heap.pop();
        }else{
            scanf("%d",&v);
            printf("%d\n",query(p[v]-1));
        }
    }
    return 0;
}
