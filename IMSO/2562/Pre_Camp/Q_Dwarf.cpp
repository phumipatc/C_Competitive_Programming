/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int maxx,minn;
};
A tree[800010];
int pos[200010];
void update(int l,int r,int now,int idx,int v){
    if(l>idx || r<idx)  return ;
    if(l == r){
        tree[now].maxx = tree[now].minn = v;
        return ;
    }
    int mid = (l+r)/2;
    update(l,mid,now*2,idx,v);
    update(mid+1,r,now*2+1,idx,v);
    tree[now].maxx = max(tree[now*2].maxx,tree[now*2+1].maxx);
    tree[now].minn = min(tree[now*2].minn,tree[now*2+1].minn);
}
A query(int l,int r,int now,int ll,int rr){
    if(l>rr || r<ll)    return {0,(int )1e9};
    if(l>=ll && r<=rr)  return tree[now];
    int mid = (l+r)/2;
    A ansl = query(l,mid,now*2,ll,rr),ansr = query(mid+1,r,now*2+1,ll,rr);
    return {max(ansl.maxx,ansr.maxx),min(ansl.minn,ansr.minn)};
}
int main(){
    int n,m,num,opr,u,v;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        pos[i] = num;
        update(1,n,1,num,i);
    }
    while(m--){
        scanf("%d %d %d",&opr,&u,&v);
        if(opr == 1){
            update(1,n,1,pos[u],v);
            update(1,n,1,pos[v],u);
            swap(pos[u],pos[v]);
        }else{
            A ans = query(1,n,1,u,v);
            if(ans.maxx-ans.minn == v-u)    printf("YES\n");
            else                            printf("NO\n");
        }
    }
	return 0;
}