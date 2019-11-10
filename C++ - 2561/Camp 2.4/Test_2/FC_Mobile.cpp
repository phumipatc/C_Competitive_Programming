/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define l first
#define r second
using namespace std;
struct A{
	int ans,maxx,minn;
};
A now;
pair<int ,int > p[100010];
int a[100010],cut[100010];
int countt = 1,minn = 1e9,maxx = 0;
void dfs(int now,int state){
	if(now == -1){
		a[countt++] = state;
		maxx = max(maxx,state);
		minn = min(minn,state);
		return ;
	}
	dfs(p[now].l,state+1);
	cut[now] = countt-1;
	dfs(p[now].r,state+1);
}
A spin(int now,int l,int r){
	if(l == r)	return {0,a[l],a[l]};
	A le = spin(p[now].l,l,cut[now]);
	A ri = spin(p[now].r,cut[now]+1,r);
	if(le.minn>=ri.maxx)	return {le.ans+ri.ans,le.maxx,ri.minn};
	if(ri.minn>=le.maxx)	return {le.ans+ri.ans+1,ri.maxx,le.minn};
	printf("-1\n");
	exit(0);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d %d",&p[i].l,&p[i].r);
	dfs(1,1);
	// for(int i=1;i<countt;i++)
	// 	printf("%d ",a[i]);
	// printf("\n");
	if(maxx-minn>1){
		printf("-1\n");
		return 0;
	}
	now = spin(1,1,countt-1);
	if(now.maxx-now.minn>1)	printf("-1\n");
	else					printf("%d\n",now.ans);
	return 0;
}
