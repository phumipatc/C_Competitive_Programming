/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
	int id,u,v,w;
	bool operator < (const A&o) const{
		return w>o.w;
	}
};
A now;
vector<int> ans;
priority_queue< A> heap;
int p[1010];
int find_root(int u){
	if(p[u] == u)	return u;
	else			return p[u] = find_root(p[u]);
}
int main(){
	// freopen("1.in","r",stdin);
	// freopen("1.sol","w",stdout);
	int n,m,u,v,w,ru,rv,sum = 0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)	p[i] = i;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&u,&v,&w);
		heap.push({i,u,v,w});
	}
	while(!heap.empty()){
		now = heap.top();
		heap.pop();
		ru = find_root(now.u);
		rv = find_root(now.v);
		if(ru == rv)	continue;
		p[ru] = rv;
		ans.push_back(now.id);
		sum+=now.w;
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",sum);
	for(int i=0;i<ans.size();i++)
		printf("%d\n",ans[i]);
    return 0;
}
