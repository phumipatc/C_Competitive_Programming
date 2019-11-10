/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int p[100100],a[100100],b[100100],value[100100];
int find_root(int u){
	if(p[u] == u)	return u;
	else			return p[u] = find_root(p[u]);
}
int main(){
	// freopen("0_in.txt","r",stdin);
	// freopen("0_out.txt","w",stdout);
	int n,u,v,ru,rv,g1,g2,x,y,idx,ans;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&value[i]),p[i] = i;
	for(int i=1;i<n-1;i++){
		scanf("%d %d",&u,&v);
		ru = find_root(u);
		rv = find_root(v);
		if(ru == rv)	continue;
		p[ru] = rv;
	}
	g1 = 1e9,g2 = -1e9;
	for(int i=1;i<=n;i++){
		p[i] = find_root(i);
		g1 = min(g1,p[i]);
		g2 = max(g2,p[i]);
	}
	x = y = 1;
	for(int i=1;i<=n;i++){
		if(p[i] == g1)	a[x++] = value[i];
		else			b[y++] = value[i];
	}
	sort(a+1,a+x);
	sort(b+1,b+y);
	ans = b[y] = 1e9;
	for(int i=1;i<x;i++){
		idx = upper_bound(b+1,b+y,a[i])-b;
		// printf("%d\n",idx);
		if(idx == 1)	ans = min(ans,abs(a[i]-b[idx]));
		else			ans = min(ans,min(abs(a[i]-b[idx]),abs(a[i]-b[idx-1])));
	}
	printf("%d\n",ans);
	return 0;
}
