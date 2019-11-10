/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int minn,maxx;
};
int a[200010],pos[200010];
A tree[800010],temp;
void build(int l,int r,int now){
    if(l == r){
        tree[now].minn = tree[now].maxx = pos[l];
        return ;
    }
    int mid = (l+r)/2;
    build(l,mid,now*2);
    build(mid+1,r,(now*2)+1);
    tree[now].minn = min(tree[now*2].minn,tree[(now*2)+1].minn);
    tree[now].maxx = max(tree[now*2].maxx,tree[(now*2)+1].maxx);
}
void update(int l,int r,int now,int idx,int v){
    if(l>idx || r<idx)  return ;
    if(l == r){
        tree[now].minn = tree[now].maxx = v;
        return ;
    }
    int mid = (l+r)/2;
    update(l,mid,now*2,idx,v);
    update(mid+1,r,(now*2)+1,idx,v);
    tree[now].minn = min(tree[now*2].minn,tree[(now*2)+1].minn);
    tree[now].maxx = max(tree[now*2].maxx,tree[(now*2)+1].maxx);
}
A query(int l,int r,int now,int ll,int rr){
    if(l>rr || r<ll)    return {(int )1e9,(int )-1e9};
    if(l>=ll && r<=rr)  return tree[now];
    int mid = (l+r)/2;
    A ansl = query(l,mid,now*2,ll,rr);
    A ansr = query(mid+1,r,(now*2)+1,ll,rr);
    return {min(ansl.minn,ansr.minn),max(ansl.maxx,ansr.maxx)};
}
int main(){
    int n,m,opr,u,v;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        pos[a[i]] = i;
    }
    build(1,n,1);
    while(m--){
        scanf("%d %d %d",&opr,&u,&v);
        if(opr == 1){
            update(1,n,1,a[u],v);
            update(1,n,1,a[v],u);
            swap(a[u],a[v]);
        }else{
            temp = query(1,n,1,u,v);
            // printf("%d %d\n",temp.minn,temp.maxx);
            if(temp.maxx-temp.minn == v-u)  printf("YES\n");
            else                            printf("NO\n");
        }
    }
	return 0;
}
