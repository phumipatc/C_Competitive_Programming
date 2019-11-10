/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,cnt,l,r;
};
A tree[800100];
pair<int,int> lazy[800100];
void update(int l,int r,int ll,int rr,int now,int v){
    if(lazy[now].first){
        tree[now].v+=lazy[now].second;
        tree[now].l+=lazy[now].second;
        tree[now].r+=lazy[now].second;
        if(l!=r){
            lazy[now*2].first = 1;
            lazy[(now*2)+1].first = 1;
            lazy[now*2].second+=lazy[now].second;
            lazy[(now*2)+1].second+=lazy[now].second;
        }
        lazy[now].first = 0;
        lazy[now].second = 0;
    }
    if(l>rr || r<ll)    return ;
    if(l>=ll && r<=rr){
        tree[now].v+=v;
        tree[now].l+=v;
        tree[now].r+=v;
        if(l!=r){
            lazy[now*2].first = 1;
            lazy[(now*2)+1].first = 1;
            lazy[now*2].second+=v;
            lazy[(now*2)+1].second+=v;
        }
        return ;
    }
    int mid=(l+r)/2;
    update(l,mid,ll,rr,now*2,v);
    update(mid+1,r,ll,rr,(now*2)+1,v);
    int L=now*2,R=L+1;
    if(tree[L].v>tree[R].v){
        tree[now]=tree[L];
    }else if(tree[L].v<tree[R].v){
        tree[now]=tree[R];
    }else{
        tree[now].v=tree[L].v;
        if(tree[L].r==tree[now].v && tree[R].l==tree[now].v) tree[now].cnt=tree[L].cnt+tree[R].cnt-1;
        else tree[now].cnt=tree[L].cnt+tree[R].cnt;
    }
    tree[now].l=tree[L].l;
    tree[now].r=tree[R].r;
}
int main(){
    int n,m,l,r,v,maxx=-1e9,countt = 0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=4*n;i++) tree[i].cnt=1;
    while(m--){
        scanf("%d %d %d",&l,&r,&v);
        update(1,n,l,r,1,v);
        printf("%d %d\n",tree[1].v,tree[1].cnt);
    }
    return 0;
}
