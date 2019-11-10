/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,d,l,r;
};
A tree[400100],now;
int lazy[400100];
void update(int l,int r,int now,int ll,int rr){
    if(lazy[now]){
        tree[now].l+=lazy[now];
        tree[now].r+=lazy[now];
        if(l!=r){
            lazy[now*2]+=lazy[now];
            lazy[now*2+1]+=lazy[now];
        }
        lazy[now] = 0;
    }
    if(r<ll || rr<l)    return ;
    if(ll<=l && r<=rr){
        tree[now].l++;
        tree[now].r++;
        if(l!=r){
            lazy[now*2]++;
            lazy[now*2+1]++;
        }
        return ;
    }
    int mid = (l+r)/2;
    update(l,mid,now*2,ll,rr);
    update(mid+1,r,now*2+1,ll,rr);
    tree[now].l = tree[now*2].l;
    tree[now].r = tree[now*2+1].r;
    tree[now].u = tree[now*2].u+tree[now*2+1].u;
    tree[now].d = tree[now*2].d+tree[now*2+1].d;
    if(tree[now*2].r<tree[now*2+1].l)       tree[now].u++;
    else if(tree[now*2].r>tree[now*2+1].l)  tree[now].d++;
}
A query(int l,int r,int now,int ll,int rr){
    if(lazy[now]){
        tree[now].l+=lazy[now];
        tree[now].r+=lazy[now];
        if(l!=r){
            lazy[now*2]+=lazy[now];
            lazy[now*2+1]+=lazy[now];
        }
        lazy[now] = 0;
    }
    if(r<ll || rr<l)    return {(int)1e9,(int)1e9,0,0};
    if(ll<=l && r<=rr)  return tree[now];
    int mid = (l+r)/2;
    A temp;
    A q1 = query(l,mid,now*2,ll,rr);
    A q2 = query(mid+1,r,now*2+1,ll,rr);
    if(q1.u == 1e9)         return q2;
    else if(q2.u == 1e9)    return q1;
    temp.u = q1.u+q2.u;
    temp.d = q1.d+q2.d;
    temp.l = q1.l;
    temp.r = q2.r;
    if(q1.r<q2.l)       temp.u++;
    else if(q1.r>q2.l)  temp.d++;
    return temp;
}
int main(){
    freopen("0_in.txt","r",stdin);
    freopen("0_out.txt","w",stdout);
    int n,m,opr,l,r;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d %d",&opr,&l,&r);
        if(opr == 1){
            update(1,n,1,l,r);
        }else if(opr == 2){
            now = query(1,n,1,l,r);
            printf("%d %d\n",now.l,now.r);
        }else if(opr == 3){
            now = query(1,n,1,l,r);
            printf("%d %d %d %d\n",now.l,now.r,now.u,now.d);
        }
    }
    return 0;
}
