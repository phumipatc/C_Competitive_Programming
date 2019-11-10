/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int tree[400010];
void update(int l,int r,int now,int idx,int v){
    if(l>idx || r<idx)  return ;
    if(l == r){
        tree[now] = v;
        return ;
    }
    int mid = (l+r)/2;
    update(l,mid,now*2,idx,v);
    update(mid+1,r,(now*2)+1,idx,v);
    tree[now] = max(tree[now*2],tree[(now*2)+1]);
}
int query(int l,int r,int now,int ll,int rr){
    if(l>rr || r<ll)    return -1e9;
    if(l>=ll && r<=rr)  return tree[now];
    int mid = (l+r)/2;
    return max(query(l,mid,now*2,ll,rr),query(mid+1,r,(now*2)+1,ll,rr));
}
int main(){
    int n,q,a,b;
    char opr;
    scanf("%d %d",&n,&q);
    while(q--){
        scanf(" %c %d %d",&opr,&a,&b);
        if(opr == 'U'){
            update(1,n,1,a,b);
        }else{
            printf("%d\n",query(1,n,1,a,b));
        }
    }
	return 0;
}
