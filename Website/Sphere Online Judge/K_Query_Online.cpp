/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1<<15;
struct A{
	A *l,*r;
	int sum;
};
A tree[1500010];
A* ver[30010];
int a[30010],b[30010];
int num;
void build(int l,int r,int now){
	num++;
	if(l == r)	return ;
	int mid = (l+r)/2;
	tree[now] = {&tree[now*2],&tree[now*2+1],0};
	build(l,mid,now*2);
	build(mid+1,r,now*2+1);
}
A* update(int l,int r,A* origin,int idx){
	int now = num;
	num++;
	tree[now] = *origin;
	if(l == r){
		tree[now].sum = 1;
		return &tree[now];
	}
	int mid = (l+r)/2;
	if(idx<=mid)	tree[now].l = update(l,mid,origin->l,idx);
	else			tree[now].r = update(mid+1,r,origin->r,idx);
	tree[now].sum = (tree[now].l->sum)+(tree[now].r->sum);
	return &tree[now];
}
pair<int ,int > query(int l,int r,A* vl,A* vr,int k){
	int sum = (vr->sum)-(vl->sum);
	if(l == r && sum == k)	return {l,0};
	if(sum<k)				return {r,1};
	if(l == r)				return {l,0};
	int mid = (l+r)/2;
	pair<int ,int > p = query(l,mid,vl->l,vr->l,k);
	if(!p.second)	return p;
	else			return query(mid+1,r,vl->r,vr->r,k-(vr->l->sum)+(vl->l->sum));
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
		b[i] = a[i];
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
		a[i] = lower_bound(b+1,b+n+1,a[i])-b;
	build(1,N,1);
	ver[0] = &tree[1];
	for(int i=1;i<=n;i++)
		ver[i] = update(1,N,ver[i-1],a[i]);
	int m,l,r,ans = 0,mid,L,R,k;
	scanf("%d",&m);
	while(m--){
        scanf("%d %d %d",&L,&R,&k);
		L^=ans,R^=ans,k^=ans;
		L = max(L,1);
		R = min(n,R);
		if(L>R){
		    printf("0\n");
			ans = 0;
			continue;
		}
		L--;
		l = 1,r = R-L+1;
		while(l<r){
			mid = (l+r)/2;
			if(b[query(1,N,ver[L],ver[R],mid).first]>=k)	r = mid;
			else											l = mid+1;
		}
		ans = max(0,R-L-l+1);
		printf("%d\n",ans);
	}
	return 0;
}
/*
6
8 9 3 5 1 9
5
2 3 5
3 3 7
0 0 11
0 0 2
3 7 4
*/