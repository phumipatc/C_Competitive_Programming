/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int tree_min[800100],tree_max[800100],a[200100],pos[200100];
void build(int l,int r,int now){
    if(l==r){
        tree_min[now]=pos[l];
        tree_max[now]=pos[l];
        return ;
    }
    int mid=(l+r)/2;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    tree_min[now]=min(tree_min[now*2],tree_min[now*2+1]);
    tree_max[now]=max(tree_max[now*2],tree_max[now*2+1]);
    return ;
}
void update_max(int l,int r,int idx,int val,int now){
    if(l>idx || r<idx)  return ;
    if(l==r){
        tree_max[now]=val;
        return ;
    }
    int mid=(l+r)/2;
    update_max(l,mid,idx,val,now*2);
    update_max(mid+1,r,idx,val,now*2+1);
    tree_max[now]=max(tree_max[now*2],tree_max[now*2+1]);
    return ;
}
void update_min(int l,int r,int idx,int val,int now){
    if(l>idx || r<idx)  return ;
    if(l==r){
        tree_min[now]=val;
        return ;
    }
    int mid=(l+r)/2;
    update_min(l,mid,idx,val,now*2);
    update_min(mid+1,r,idx,val,now*2+1);
    tree_min[now]=min(tree_min[now*2],tree_min[now*2+1]);
    return ;
}
int query_min(int l,int r,int ll,int rr,int now){
    if(l>rr || r<ll)    return 1e9;
    if(l>=ll && r<=rr)  return tree_min[now];
    int mid=(l+r)/2;
    return min(query_min(l,mid,ll,rr,now*2),query_min(mid+1,r,ll,rr,now*2+1));
}
int query_max(int l,int r,int ll,int rr,int now){
    if(l>rr || r<ll)    return -1e9;
    if(l>=ll && r<=rr)  return tree_max[now];
    int mid=(l+r)/2;
    return max(query_max(l,mid,ll,rr,now*2),query_max(mid+1,r,ll,rr,now*2+1));
}
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        pos[a[i]]=i;
    }
    build(1,n,1);
    while(m--){
        int opr,r,s;
        cin >> opr;
        if(opr==1){
            cin >> r >> s;
            update_max(1,n,a[r],s,1);
            update_min(1,n,a[r],s,1);
            update_max(1,n,a[s],r,1);
            update_min(1,n,a[s],r,1);
            swap(a[r],a[s]);
        }else{
            cin >> r >> s;
            int d=query_max(1,n,r,s,1)-query_min(1,n,r,s,1);
            printf((d==s-r)?"YES\n":"NO\n");
        }
    }
    return 0;
}
/*
7 7
4 7 3 5 1 2 6
2 1 7
1 3 7
2 4 6
2 4 7
2 1 4
1 1 4
2 1 4
*/
