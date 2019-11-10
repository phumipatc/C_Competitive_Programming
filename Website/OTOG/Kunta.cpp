/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int tree[400010],lazy[400010];
void update(int l,int r,int now,int ll,int rr,int v){
    if(r<ll || l>rr)    return ;
    if(lazy[now]){
        tree[now]+=lazy[now];
        if(l!=r){
            lazy[now*2]+=lazy[now];
            lazy[now*2+1]+=lazy[now];
        }
        lazy[now] = 0;
    }
    if(l>=ll && r<=rr){
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
    tree[now] = max(tree[now*2],tree[now*2+1]);
}
int query(int l,int r,int now,int ll,int rr){
    if(r<ll || l>rr)    return 0;
    if(lazy[now]){
        tree[now]+=lazy[now];
        if(l!=r){
            lazy[now*2]+=lazy[now];
            lazy[now*2+1]+=lazy[now];
        }
        lazy[now] = 0;
    }
    if(l>=ll && r<=rr)  return tree[now];
    int mid = (l+r)/2;
    return max(query(l,mid,now*2,ll,rr),query(mid+1,r,now*2+1,ll,rr));
}
int main(){
    int n,m,p,x,y,z,countt = 0;
    scanf("%d %d %d",&n,&m,&p);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&x,&y,&z);
        if(query(1,n,1,x,y-1)+z>p){
            countt+=z;
            continue;
        }
        update(1,n,1,x,y-1,z);
    }
    printf("%d\n",countt);
	return 0;
}