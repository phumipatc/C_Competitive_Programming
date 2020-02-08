/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define N 500010
#define lgn 20
using namespace std;
int L[N*lgn],R[N*lgn],sum[N*lgn],root[N];
int sizee = 0;
int Copy(int u,int &v){
    sizee++;
    L[sizee] = L[u];
    R[sizee] = R[u];
    sum[sizee] = sum[u];
    return v = sizee;
}
void update(int p,int idx,int l,int r){
    if(l == r){
        sum[p] = 1;
        return ;
    }
    int mid = (l+r)>>1;
    if(idx<=mid)    update(Copy(L[p],L[p]),idx,l,mid);
    else            update(Copy(R[p],R[p]),idx,mid+1,r);
    sum[p] = sum[L[p]]+sum[R[p]];
}
int query(int p,int q,int k,int l,int r,int SUM){
    //p = 1 to Ql-1 && q = 1 to Qr
    if(l == r)  return l;
    int mid = (l+r)>>1;
    if((sum[L[q]]-sum[L[p]])+SUM>=k)    return query(L[p],L[q],k,l,mid,SUM);
    else                                return query(R[p],R[q],k,mid+1,r,SUM+(sum[L[q]]-sum[L[p]]));
}
int main(){
    int n,q,l,r,k,now,i;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&now);
        Copy(root[i-1],root[i]);
        update(root[i],now,1,n);
    }
    while(q--){
        scanf("%d %d %d",&l,&r,&k);
        printf("%d\n",query(root[l-1],root[r],k,1,n,0));
    }
	return 0;
}