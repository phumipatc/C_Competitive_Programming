/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int tree[500100],lazy[500100];
void update(int l,int r,int ll,int rr,int now){
    if(lazy[now]){
        tree[now]=r-l+1-tree[now];
        if(l!=r){
            lazy[now*2]^=1;
            lazy[now*2+1]^=1;
        }
        lazy[now]^=1;
    }
    if(l>rr || r<ll)    return ;
    if(l>=ll && r<=rr){
        tree[now]=r-l+1-tree[now];
        if(l!=r){
            lazy[now*2]^=1;
            lazy[now*2+1]^=1;
        }
        return ;
    }
    int mid=(l+r)/2;
    update(l,mid,ll,rr,now*2);
    update(mid+1,r,ll,rr,now*2+1);
    tree[now]=tree[now*2]+tree[now*2+1];
    return ;
}
int query(int l,int r,int ll,int rr,int now){
    if(lazy[now]){
        tree[now]=r-l+1-tree[now];
        if(l!=r){
            lazy[now*2]^=1;
            lazy[now*2+1]^=1;
        }
        lazy[now]^=1;
    }
    if(l>rr || r<ll)    return 0;
    if(l>=ll && r<=rr)  return tree[now];
    int mid=(l+r)/2;
    int query1=query(l,mid,ll,rr,now*2),query2=query(mid+1,r,ll,rr,now*2+1);
    tree[now]=tree[now*2]+tree[now*2+1];
    return query1+query2;
}
int main()
{
    int n,q;
    cin >> n >> q;
    while(q--){
        int c;
        cin >> c;
        if(c==0){
            int i,z;
            cin >> i >> z;
            update(1,n,i,z,1);
        }else{
            int a,b;
            cin >> a >> b;
            cout << query(1,n,a,b,1) << endl;
        }
    }
    return 0;
}
