/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int tree[800100],lazy[800100];
void update(int l,int r,int now,int ll,int rr,int v){
    if(lazy[now]){
        tree[now]+=lazy[now];
        if(l!=r){
            lazy[now*2]+=lazy[now];
            lazy[now*2+1]+=lazy[now];
        }
        lazy[now] = 0;
    }
    if(r<ll || rr<l)    return ;
    if(ll<=l && r<=rr){
        tree[now]+=v;
        if(l!=r){
            lazy[now*2]+=v;
            lazy[now*2+1]+=v;
        }
        return ;
    }
    int mid = (l+r)/2;
    update(l,mid,now*2,ll,rr,v);
    update(mid+1,r,now*2+1,ll,rr,v);
    tree[now] = tree[now*2]+tree[now*2+1];
}
int query(int l,int r,int now,int idx){
    if(lazy[now]){
        tree[now]+=lazy[now];
        if(l!=r){
            lazy[now*2]+=lazy[now];
            lazy[now*2+1]+=lazy[now];
        }
        lazy[now] = 0;
    }
    if(l == r && l == idx)  return tree[now];
    int mid = (l+r)/2;
    if(idx<=mid)    return query(l,mid,now*2,idx);
    else            return query(mid+1,r,now*2+1,idx);
}
int main(){
    int n,m,opr,l,r,v;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d",&opr);
        if(opr == 1){
            scanf("%d %d %d",&l,&r,&v);
            update(1,n,1,l,r,v);
        }else{
            scanf("%d",&v);
            printf("%d\n",query(1,n,1,v));
        }
    }
    return 0;
}
