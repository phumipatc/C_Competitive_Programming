/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int tree[400100],a[100100],idx = 1;
void build(int l,int r,int now){
    if(l == r){
        tree[now] = a[idx++];
        return ;
    }
    int mid = (l+r)/2;
    update(l,mid,now*2,idx,v);
    update(mid+1,r,(now*2)+1,idx,v);
    tree[now] = max(tree[now*2],tree[(now*2)+1]);
}
void update(int l,int r,int now,int idx,int v){
    if(l>idx || r<idx)  return ;
    if(l == r){
        if(l == idx)
            tree[now] = v;
        return ;
    }
    int mid = (l+r)/2;
    update(l,mid,now*2,idx,v);
    update(mid+1,r,(now*2)+1,idx,v);
    tree[now] = max(tree[now*2],tree[(now*2)+1]);
}
int main(){
    return 0;
}
