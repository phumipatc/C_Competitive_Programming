/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y;
};
map<int,int> mapp;
A a[100010];
int compress[200010],tree[800010],lazy[800010];
void update(int l,int r,int now,int ll,int rr){
    if(lazy[now]){
        tree[now]+=lazy[now];
        if(l!=r)    lazy[now*2]+=lazy[now],lazy[now*2+1]+=lazy[now];
        lazy[now] = 0;
    }
    if(l>rr || r<ll)    return ;
    // printf("Update: %d %d %d %d %d %d\n",l,r,now,ll,rr,tree[now]);
    if(l>=ll && r<=rr){
        tree[now]++;
        if(l!=r)    lazy[now*2]++,lazy[now*2+1]++;
        return ;
    }
    int mid = (l+r)/2;
    update(l,mid,now*2,ll,rr);
    update(mid+1,r,now*2+1,ll,rr);
    tree[now] = max(tree[now*2],tree[now*2+1]);
}
int query(int l,int r,int now,int ll,int rr){
    if(lazy[now]){
        tree[now]+=lazy[now];
        if(l!=r)    lazy[now*2]+=lazy[now],lazy[now*2+1]+=lazy[now];
        lazy[now] = 0;
    }
    if(l>rr || r<ll)    return 0;
    // printf("Query: %d %d %d %d %d %d\n",l,r,now,ll,rr,tree[now]);
    if(l>=ll && r<=rr)  return tree[now];
    int mid = (l+r)/2;
    int ansl = query(l,mid,now*2,ll,rr);
    int ansr = query(mid+1,r,now*2+1,ll,rr);
    tree[now] = max(tree[now*2],tree[now*2+1]);
    return max(ansl,ansr);
}
int main(){
    int n,k,st,en;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&a[i].x,&a[i].y);
        compress[(2*i)-1] = a[i].x;
        compress[2*i] = a[i].y;
    }
    sort(compress+1,compress+(2*n)+1);
    for(int i=1;i<=n;i++){
        st = lower_bound(compress+1,compress+(2*n)+1,a[i].x)-compress;
        en = lower_bound(compress+1,compress+(2*n)+1,a[i].y)-compress;
        // printf("%d %d %d\n",st,en,query(1,n,1,st,en));
        if(query(1,2*n,1,st,en)<k){
            printf("yes\n");
            update(1,2*n,1,st,en);
        }else   printf("no\n");
    }
    return 0;
}
