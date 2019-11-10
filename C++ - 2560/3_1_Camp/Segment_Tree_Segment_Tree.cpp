/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int tree[400010];
void update(int l,int r,int idx,int now,int val){
    if(l>r || l>idx || r<idx)   return ;
    if(l == r){
        tree[now] = val;
        return ;
    }
    int mid = (l+r)/2;
    update(l,mid,idx,now*2,val);
    update(mid+1,r,idx,(now*2)+1,val);
    tree[now] = max(tree[now*2],tree[(now*2)+1]);
}
int query(int l,int r,int ll,int rr,int now){
    if(l>r || l>rr || r<ll) return -1e9;
    if(l>=ll && r<=rr)      return tree[now];
    int mid = (l+r)/2;
    return max(query(l,mid,ll,rr,now*2),query(mid+1,r,ll,rr,(now*2)+1));
}
int main(){
    int n,q,a,b;
    char opr;
    cin >> n >> q;
    while(q--){
        cin >> opr >> a >> b;
        if(opr == 'U')
            update(1,n,a,1,b);
        else{
            printf("%d\n",query( 1, n, a, b, 1 ));
        }
    }
    return 0;
}
