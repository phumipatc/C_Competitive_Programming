/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
pair<int ,int > a[100010],b[100010];
int tree[400010][2],bs[100010];
void build(int l,int r,int now){
    if(l == r){
        tree[now][0] = b[l].second+b[l].first;
        tree[now][0] = b[l].second-b[l].first;
        return ;
    }
    int mid = (l+r)/2;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    tree[now][0] = max(tree[now*2][0],tree[now*2+1][0]);
    tree[now][1] = max(tree[now*2][1],tree[now*2+1][1]);
}
int query(int l,int r,int now,int ll,int rr,int state){
    if(rr<ll)           return -1e9;
    if(l>rr || r<ll)    return -1e9;
    if(l>=ll && r<=rr)  return tree[now][state];
    int mid = (l+r)/2;
    return max(query(l,mid,now*2,ll,rr,state),query(mid+1,r,now*2+1,ll,rr,state));
}
int main(){
    int n,idx,ans;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&a[i].first,&a[i].second);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&b[i].first,&b[i].second);
    sort(b+1,b+n+1);
    build(1,n,1);
    for(int i=1;i<=n;i++)
        bs[i] = b[i].first;
    for(int i=1;i<=n;i++){
        idx = upper_bound(bs+1,bs+n+1,a[i].first)-bs;
        ans = a[i].second + max(query(1,n,1,1,idx-1,0)-a[i].first,query(1,n,1,idx,n,1)+a[i].first);
        printf("%d\n",ans);
    }
	return 0;
}