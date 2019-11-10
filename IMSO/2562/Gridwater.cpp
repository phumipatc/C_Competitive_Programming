/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
	int u,v,w;
	bool operator < (const A&o) const{
		return w>o.w;
	}
};
A now;
vector<A > unused;
priority_queue<A > heap;
struct B{
	int v,w;
};
vector<B > g[160010],g2[160010];
int p[160010],LCA[160010][20],weight[160010][20],lv[160010];
int find_root(int u){
	if(p[u] == u)	return u;
	else			return p[u] = find_root(p[u]);
}
void dfs(int u,int pa,int w,int state){
    // printf("processing: %d %d %d %d\n",u,pa,w,state);
    LCA[u][0] = pa;
    lv[u] = state;
    weight[u][0] = w;
    for(int i=1;i<18;i++){
        LCA[u][i] = LCA[LCA[u][i-1]][i-1];
        weight[u][i] = max(weight[u][i-1],weight[LCA[u][i-1]][i-1]);
    }
    for(auto x:g2[u]){
        if(x.v == pa)   continue;
        dfs(x.v,u,x.w,state+1);
    }
}
int main(){
	int n,m,w,num = 0,ru,rv;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=2*n-1;i++){
		if(i%2){
			for(int j=1;j<m;j++){
				scanf("%d",&w);
				g[(num*m)+j].push_back({(num*m)+j+1,w});
				g[(num*m)+j+1].push_back({(num*m)+j,w});
				heap.push({(num*m)+j,(num*m)+j+1,w});
				// printf("%d %d %d\n",(num*m)+j,(num*m)+j+1,w);
			}
		}else{
			for(int j=1;j<=m;j++){
				scanf("%d",&w);
				g[(num*m)+j].push_back({(num*m)+m+j,w});
				g[(num*m)+m+j].push_back({(num*m)+j,w});
				heap.push({(num*m)+j,(num*m)+m+j,w});
				// printf("%d %d %d\n",(num*m)+j,(num*m)+j+m,w);
			}
			num++;
		}
	}
	for(int i=1;i<=n*m;i++)
		p[i] = i;
	int sum = 0;
	while(!heap.empty()){
		now = heap.top();
		heap.pop();
		ru = find_root(now.u);
		rv = find_root(now.v);
		if(ru == rv){
			unused.push_back(now);
			continue;
		}
		p[ru] = rv;
		g2[now.u].push_back({now.v,now.w});
		g2[now.v].push_back({now.u,now.w});
		sum+=now.w;
	}
	dfs(1,0,0,1);
	int ans = 1e9;
	for(auto x:unused){
		int tu = x.u,tv = x.v,maxx = 0;
        if(lv[tu]>lv[tv])   swap(tu,tv);
        for(int i=17;i>=0;i--){
            if(lv[LCA[tv][i]]<lv[tu])   continue;
            maxx = max(maxx,weight[tv][i]);
            tv = LCA[tv][i];
        }
        // printf("processing: %lld %lld %lld\n",tu,tv,maxx);
        if(tu!=tv){
            for(int i=17;i>=0;i--){
                if(LCA[tu][i] == LCA[tv][i])    continue;
                maxx = max(maxx,max(weight[tu][i],weight[tv][i]));
                tu = LCA[tu][i],tv = LCA[tv][i];
            }
            maxx = max(maxx,max(weight[tu][0],weight[tv][0]));
        }
		// printf("%d %d %d\n",sum,maxx,x.w);
		ans = min(ans,-maxx+x.w);
	}
	printf("%d\n",ans);
	return 0;
}