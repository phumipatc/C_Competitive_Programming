/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int t,num,v;
    bool operator <(const A & o)const{
        if(t != o.t)  return t > o.t;
    }
};
priority_queue < A> heap;
int value[100100],p[100100],sum[100100];
int find_root(int i){
    if(p[i]==i)   return i;
    else           return find_root(p[i]);
}
void update(int now,int root){
    sum[now] -= sum[root];
    if(p[now] == now) return ;
    update(p[now],root);
}
int main()
{

    int n,q,i,opr,a,b,t,v,ra,rb;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&value[i]);
        p[i] = i,sum[i] = value[i];
    }
    for(i=1;i<=q;i++){
        scanf("%d",&opr);
        while(!heap.empty() && i>heap.top().t)  heap.pop();
        while(!heap.empty() && i == heap.top().t){
            ra = find_root(heap.top().num);
            sum[ra]+=heap.top().v;
            value[ra]+=heap.top().v;
            heap.pop();
        }
        if(opr == 1){
            scanf("%d",&a);
            if(p[a] == a)   continue;
            update(p[a],a);
            p[a] = a;
        }else if(opr == 2){
            scanf("%d %d %d %d",&a,&b,&t,&v);
            ra = find_root(a);
            rb = find_root(b);
            if(rb == a) continue;
            if(p[a]!=a) update(p[a],a);
            p[a]=rb;
            sum[rb]+=sum[a];
            heap.push({t,a,v});
        }else if(opr == 3){
            scanf("%d",&a);
            ra = find_root(a);
            printf("%d\n",sum[ra]);
        }
    }
    return 0;
}
