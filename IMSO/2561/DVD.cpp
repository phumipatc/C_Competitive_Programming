/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int maxx[400100],minn[400100],a[100100],idx = 1;
void build(int l,int r,int now){
    if(l == r){
        maxx[now] = idx;
        minn[now] = idx;
        idx++;
        return ;
    }
    int mid = (l+r)/2;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    maxx[now] = max(maxx[now*2],maxx[now*2+1]);
    minn[now] = min(minn[now*2],minn[now*2+1]);
}
void update(int l,int r,int now,int idx,int v){
    if(l == r && l == idx){
        maxx[now] = v;
        minn[now] = v;
        return ;
    }
    if(r<idx || l>idx)  return ;
    int mid = (l+r)/2;
    update(l,mid,now*2,idx,v);
    update(mid+1,r,now*2+1,idx,v);
    maxx[now] = max(maxx[now*2],maxx[now*2+1]);
    minn[now] = min(minn[now*2],minn[now*2+1]);
}
int ma,mi;
void query(int l,int r,int now,int ll,int rr){
    if(r<ll || rr<l)    return ;
    if(ll<=l && r<=rr){
        ma = max(ma,maxx[now]);
        mi = min(mi,minn[now]);
        return ;
    }
    int mid = (l+r)/2;
    query(l,mid,now*2,ll,rr);
    query(mid+1,r,now*2+1,ll,rr);
}
int main(){
    int n,k,opr,l,r;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        a[i] = i;
    build(1,n,1);
    while(k--){
        scanf("%d %d %d",&opr,&l,&r);
        l++,r++;
        ma = -1e9,mi = 1e9;
        if(opr == 0){
            update(1,n,1,l,a[r]);
            update(1,n,1,r,a[l]);
            swap(a[l],a[r]);
        }else{
            query(1,n,1,l,r);
            if(ma == r && mi == l)  printf("YES\n");
            else                    printf("NO\n");
        }
    }
    return 0;
}
