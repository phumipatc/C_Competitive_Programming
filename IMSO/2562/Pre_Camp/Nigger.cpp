/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int tree[400010],lazy[400010];
void update(int l,int r,int now,int ll,int rr){
    if(lazy[now]){
        tree[now] = (r-l+1)-tree[now];
        if(l!=r)    lazy[now*2]^=1,lazy[now*2+1]^=1;
        lazy[now] = 0;
    }
    if(l>rr || r<ll)    return ;
    if(l>=ll && r<=rr){
        tree[now] = (r-l+1)-tree[now];
        if(l!=r)    lazy[now*2]^=1,lazy[now*2+1]^=1;
        return ;
    }
    int mid = (l+r)/2;
    update(l,mid,now*2,ll,rr);
    update(mid+1,r,now*2+1,ll,rr);
    tree[now] = tree[now*2]+tree[now*2+1];
}
int query(int l,int r,int now,int ll,int rr){
    if(lazy[now]){
        tree[now] = (r-l+1)-tree[now];
        if(l!=r)    lazy[now*2]^=1,lazy[now*2+1]^=1;
        lazy[now] = 0;
    }
    if(l>rr || r<ll)    return 0;
    if(l>=ll && r<=rr)  return tree[now];
    int mid = (l+r)/2;
    int ans = query(l,mid,now*2,ll,rr)+query(mid+1,r,now*2+1,ll,rr);
    tree[now] = tree[now*2]+tree[now*2+1];
    return ans;
}
int main(){
    int n,m,opr,u,v;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d %d",&opr,&u,&v);
        if(opr == 0)    update(1,n,1,u,v);
        else            printf("%d\n",query(1,n,1,u,v));
    }
	return 0;
}