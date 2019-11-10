/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
	int maxx[2][2];
};
A tree[4000010];
char opr[10];
int lazy[4000010],a[1000010];
void build(int l,int r,int now){
	if(l == r){
		if(a[l] == 0)	tree[now].maxx[0][0] = 1;
		else			tree[now].maxx[1][1] = 1;
		return ;
	}
	int mid = (l+r)/2;
	build(l,mid,now*2);
	build(mid+1,r,now*2+1);
	A ansl = tree[now*2];
	A ansr = tree[now*2+1];
	tree[now].maxx[0][0] = ansl.maxx[0][0]+ansr.maxx[0][0];
	tree[now].maxx[0][1] =	max(ansl.maxx[0][0]+ansr.maxx[0][1],
							max(ansl.maxx[0][0]+ansr.maxx[1][1],ansl.maxx[0][1]+ansr.maxx[1][1]));
	tree[now].maxx[1][0] =	max(ansl.maxx[1][1]+ansr.maxx[0][0],
							max(ansl.maxx[1][1]+ansr.maxx[1][0],ansl.maxx[1][0]+ansr.maxx[0][0]));
	tree[now].maxx[1][1] = ansl.maxx[1][1]+ansr.maxx[1][1];
}
void update(int l,int r,int now,int ll,int rr){
	if(lazy[now]){
		swap(tree[now].maxx[0][0],tree[now].maxx[1][1]);
		swap(tree[now].maxx[0][1],tree[now].maxx[1][0]);
		if(l!=r)	lazy[now*2]^=1,lazy[now*2+1]^=1;
		lazy[now] = 0;
	}
	if(r<ll || l>rr)	return ;
	if(l>=ll && r<=rr){
		swap(tree[now].maxx[0][0],tree[now].maxx[1][1]);
		swap(tree[now].maxx[0][1],tree[now].maxx[1][0]);
		if(l!=r)	lazy[now*2]^=1,lazy[now*2+1]^=1;
		return ;
	}
	int mid = (l+r)/2;
	update(l,mid,now*2,ll,rr);
	update(mid+1,r,now*2+1,ll,rr);
	A ansl = tree[now*2];
	A ansr = tree[now*2+1];
	tree[now].maxx[0][0] = ansl.maxx[0][0]+ansr.maxx[0][0];
	tree[now].maxx[0][1] =	max(ansl.maxx[0][0]+ansr.maxx[0][1],
							max(ansl.maxx[0][0]+ansr.maxx[1][1],ansl.maxx[0][1]+ansr.maxx[1][1]));
	tree[now].maxx[1][0] =	max(ansl.maxx[1][1]+ansr.maxx[0][0],
							max(ansl.maxx[1][1]+ansr.maxx[1][0],ansl.maxx[1][0]+ansr.maxx[0][0]));
	tree[now].maxx[1][1] = ansl.maxx[1][1]+ansr.maxx[1][1];
}
int main(){
	int n,m,l,r;
	char c;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf(" %c",&c);
		if(c == '4')	a[i] = 0;
		else			a[i] = 1;
	}
	build(1,n,1);
	while(m--){
		scanf(" %s",opr+1);
		if(opr[1] == 's'){
			scanf("%d %d",&l,&r);
			update(1,n,1,l,r);
		}else{
			printf("%d\n",max(tree[1].maxx[0][0],max(tree[1].maxx[0][1],tree[1].maxx[1][1])));
		}
	}
	return 0;
}