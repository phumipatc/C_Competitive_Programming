/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v;
    char opr;
};
A a[300010];
struct B{
	int u,w;
};
B now;
queue<B > que;
vector<int > g[300010],gt[300010];
int p[300010],ing[300010],ingt[300010],lvg[300010],lvgt[300010];
int find_root(int idx){
    if(p[idx] == idx)   return idx;
    else                return p[idx] = find_root(p[idx]);
}
int main(){
    int n,m,q;
    char opr;
    scanf("%d %d %d",&n,&m,&q);
    for(int i=1;i<=m;i++)   p[i] = i;
    for(int i=1;i<=q;i++){
        scanf("%d %c %d",&a[i].u,&a[i].opr,&a[i].v);
        if(a[i].opr == '=')
            p[find_root(a[i].u)] = find_root(a[i].v);
    }
    for(int i=1;i<=q;i++){
        if(a[i].opr == '=') continue;
        g[find_root(a[i].u)].push_back(find_root(a[i].v));
        gt[find_root(a[i].v)].push_back(find_root(a[i].u));
        ing[find_root(a[i].v)]++;
        ingt[find_root(a[i].u)]++;
    }
    for(int i=1;i<=m;i++){
        if(ing[find_root(i)])	continue;
        ing[find_root(i)]--;
		lvg[find_root(i)] = 1;
		que.push({find_root(i),1});
    }
	while(!que.empty()){
		now = que.front();
		que.pop();
		for(auto x:g[now.u]){
			ing[x]--;
			lvg[x] = max(lvg[x],now.w+1);
			if(ing[x])	continue;
			que.push({x,now.w+1});
		}
	}
	for(int i=1;i<=m;i++){
        if(ingt[find_root(i)])	continue;
        ingt[find_root(i)]--;
		lvgt[find_root(i)] = 1;
		que.push({find_root(i),1});
    }
	while(!que.empty()){
		now = que.front();
		que.pop();
		for(auto x:gt[now.u]){
			ingt[x]--;
			lvgt[x] = max(lvgt[x],now.w+1);
			if(ingt[x])	continue;
			que.push({x,now.w+1});
		}
	}
	for(int i=1;i<=m;i++){
		if(lvg[find_root(i)]+lvgt[find_root(i)]-1 == n)	printf("K%d\n",lvg[find_root(i)]);
		else											printf("?\n");
	}
	return 0;
}
