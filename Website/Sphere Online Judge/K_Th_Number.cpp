/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct A{
	A *l,*r;
	int sum;
};
A tree[5000010];
A* ver[100010];
int a[100010],comp[100010];
int num;
void build(int l,int r,int now){
	num++;
	if(l == r)	return ;
	tree[now] = {&tree[now*2],&tree[now*2+1],0};
	int mid = (l+r)/2;
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
	tree[now].sum++;
	return &tree[now];
}
pair<int ,int > query(int l,int r,A* vl,A* vr,int k){
	int sum = (vr->sum) - (vl->sum);
	if(l == r && sum == k)	return {l,0};
	if(sum<k)				return {r,1};
	if(l == r)				return {l,0};
	int mid = (l+r)/2;
	pair<int ,int > p = query(l,mid,vl->l,vr->l,k);
	if(!p.second)	return p;
	else			return query(mid+1,r,vl->r,vr->r,k-(vr->l->sum)+(vl->l->sum));
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		comp[i] = a[i];
	}
	sort(comp+1,comp+n+1);
	for(int i=1;i<=n;i++)
		a[i] = lower_bound(comp+1,comp+n+1,a[i])-comp;
	ver[0] = &tree[1];
	build(1,1<<17,1);
	for(int i=1;i<=n;i++)
		ver[i] = update(1,1<<17,ver[i-1],a[i]);
	int l,r,k;
	while(m--){
		cin >> l >> r >> k;
		cout << comp[query(1,1<<17,ver[l-1],ver[r],k).first] << '\n';
	}
	return 0;
}