/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int idx = 1,tree[450000],a[200010],qs[200010];
void build(int l,int r,int now){
    if(l == r){
        tree[now] = qs[idx++];
        return ;
    }
    int mid = (l+r)/2;
    build(l,mid,now*2);
    build(mid+1,r,(now*2)+1);
    tree[now] = ;
    return ;
}
int query(int l,int r,int now,int ll,int rr){
    if(l>rr || r<ll)    return -1e9;
    if(l == r)          return tree[now];
    int mid = (l+r)/2;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        qs[i] = a[i]+qs[i-1];
    }
    build(1,n,1);
    while(m--){
        scanf("%d %d",&a,&b);
        query(1,n,1,a,b);
    }
    return 0;
}
