/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int q[100100],comp[100100],tree[400100],lazy[400100];
void build(int l,int r,int now){
    if(l == r){
        tree[now] = comp[r]-comp[l-1];
        return ;
    }
    int mid = (l+r)/2;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    tree[now] = tree[now*2]+tree[now*2+1];
}
void update(int l,int r,int now,int ll,int rr){
    if(lazy[now]){
        tree[now] = (comp[r]-comp[l-1])-tree[now];
        if(l!=r){
            lazy[now*2]^=1;
            lazy[now*2+1]^=1;
        }
        lazy[now]^=1;
    }
    if(ll>r || rr<l)    return ;
    if(ll<=l && r<=rr){
        tree[now] = (comp[r]-comp[l-1])-tree[now];
        if(l!=r){
            lazy[now*2]^=1;
            lazy[now*2+1]^=1;
        }
        return ;
    }
    int mid = (l+r)/2;
    update(l,mid,now*2,ll,rr);
    update(mid+1,r,now*2+1,ll,rr);
    tree[now] = tree[now*2]+tree[now*2+1];
}
int main(){
    int n,m,idx = 0,now;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d",&q[i]);
        q[i]++;
        comp[i] = q[i];
    }
    comp[m] = 1;
    comp[m+1] = n;
    comp[m+2] = n+1;
    sort(comp,comp+m+2);
    for(int i=0;i<m+2;i++)
        if(comp[i]!=comp[i+1])
            comp[idx++] = comp[i];
    build(1,idx,1);
    for(int i=0;i<m;i++){
        now = lower_bound(comp,comp+idx,q[i])-comp+1;
        update(1,idx,1,now,idx);
        printf("%d\n",tree[1]);
    }
    return 0;
}
