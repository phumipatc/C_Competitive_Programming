/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[200010],qs[200010],tree[800010],idx = 1;
void update(int l,int r,int now){
    if(l == r){
        tree[now] = a[idx++];
        return ;
    }
    int mid = (l+r)/2;
    update(l,mid,now*2);
    update(mid+1,r,(now*2)+1);
    tree[now] = max(tree[now*2],tree[(now*2)+1]);
}
int query(int l,int r,int ll,int rr,int now){
    if(ll>r || rr<l)    return -1e9;
    if(l == r)          return tree[now];
    int mid = (l+r)/2,ans,m1 = -1e9,m2 = -1e9;
    ans = max(query(l,mid,ll,rr,now*2),query(mid+1,r,ll,rr,(now*2)+1));
    ans = max(ans,m1+m2);
    return ans;
}
int main(){
    int n,m,l,r;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        qs[i] = a[i]+qs[i-1];
    update(1,n,1);
    while(m--){
        scanf("%d %d",&l,&r);
        l++,r++;
        int ans = query(1,n,l,r,1);
        if(ans<0)   printf("0\n");
        else        printf("%d\n",ans);
    }
    return 0;
}
