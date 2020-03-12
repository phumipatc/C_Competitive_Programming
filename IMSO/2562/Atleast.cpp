/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
typedef long long LL;
const int N = 1<<17;
struct A{
	A *l,*r;
	int num,sum;
};
A tree[5000010];
A* ver[100010];
int a[100010];
vector<LL > v;
int maxx;
void build(int l,int r,int now){
	maxx++;
	if(l == r)	return ;
	int mid = (l+r)/2;
	tree[now] = {&tree[now*2],&tree[now*2+1],0,0};
	build(l,mid,now*2);
	build(mid+1,r,now*2+1);
}
A* update(int l,int r,A* origin,int idx){
	int now = maxx;
	maxx++;
	tree[now] = *origin;
	if(l == r){
		tree[now].sum+=v[idx-1];
		tree[now].num++;
		return &tree[now];
	}
	int mid = (l+r)/2;
	if(idx<=mid)	tree[now].l = update(l,mid,origin->l,idx);
	else			tree[now].r = update(mid+1,r,origin->r,idx);
	tree[now].num = (tree[now].l->num) + (tree[now].r->num);
	tree[now].sum  = (tree[now].l->sum) + (tree[now].r->sum);
	return &tree[now];
}
int query(int l,int r,A* vl,A* vr,int k){
	// printf("%d %d %d\n",l,r,k);
	int num = (vr->num)-(vl->num);
	if(k == 0)	return (vr->sum)-(vl->sum);
	if(num<=k)	return 0;
	if(l == r)	return v[l-1]*k;
	int mid = (l+r)/2;
	int ret = query(l,mid,vl->l,vr->l,k);
	if(ret)	return ret+query(mid+1,r,vl->r,vr->r,0);
	else	return query(mid+1,r,vl->r,vr->r,k-(vr->l->num)+(vl->l->num));
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		v.push_back(a[i]);
	}
	// return 0;
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());
	for(int i=1;i<=n;i++)
		a[i] = lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
	build(1,N,1);
	ver[0] = &tree[1];
	for(int i=1;i<=n;i++)
		ver[i] = update(1,N,ver[i-1],a[i]);
	int ll,rr,l,r,mid;
	double w;
	while(m--){
		scanf("%d %d %lf",&ll,&rr,&w);
		// printf("%lf\n",w);
		ll--;
		l = 0,r = rr-ll+1;
		while(l<r){
			mid = (l+r)/2;
			double sum;
			if(mid == rr-ll)	sum = 0;
			else				sum = (double )query(1,N,ver[ll],ver[rr],mid)/(rr-ll-mid);
			// printf("mid:%d %f\n",mid,(float )sum/(rr-ll-mid));
			if(sum>=w)	r = mid;
			else		l = mid+1;
			// getch();
		}
		if(l == rr-ll+1)	printf("-1\n");
		else				printf("%d\n",l);
	}
	return 0;
}