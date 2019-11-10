/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int tree[500100];
void build(int l,int r,int now){
    if(l==r){
        tree[now]=0;
        return ;
    }
    int mid=(l+r)/2;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    return ;
}
void update(int l,int r,int idx,int val,int now){
    if(l>idx || r<idx)  return ;
    if(l==r){
        tree[now]=val;
        return ;
    }
    int mid=(l+r)/2;
    update(l,mid,idx,val,now*2);
    update(mid+1,r,idx,val,now*2+1);
    tree[now]=max(tree[now*2],tree[now*2+1]);
    return ;
}
int query(int l,int r,int ll,int rr,int now){
    if(l>rr || r<ll)    return -1e9;
    if(l>=ll && r<=rr)  return tree[now];
    int mid=(l+r)/2;
    return max(query(l,mid,ll,rr,now*2),query(mid+1,r,ll,rr,now*2+1));
}
int main()
{
    int n,q;
    cin >> n >> q;
    build(1,n,1);
    while(q--){
        char c;
        cin >> c;
        if(c=='U'){
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
