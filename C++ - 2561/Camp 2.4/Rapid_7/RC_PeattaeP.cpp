/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,id;
};
vector<A > g[100010];
stack<int > st;
set<int > a,b;
int idx[100010],low[100010],onstack[100010];
int countt = 1,num = 0;
void dfs(int now,int p){
    idx[now] = low[now] = countt++;
    onstack[now] = 1;
    st.push(now);
    for(auto x:g[now]){
        if(x.v == p)    continue;
        if(!idx[x.v]){
            if(now == 0)    num++;
            dfs(x.v,now);
            low[now] = min(low[now],low[x.v]);
			if(now == 0){
				if(num>1)	a.insert(now);
			}else if(idx[now]<=low[x.v])	a.insert(now);
			if(idx[now]<low[x.v])			b.insert(x.id);
		}else if(onstack[x.v]){
            low[now] = min(low[now],idx[x.v]);
        }
    }
    if(idx[now] == low[now]){
        while(st.top()!=now){
            onstack[st.top()] = 0;
            st.pop();
        }
        onstack[now] = 0;
        st.pop();
    }
}
int main(){
    int n,m,u,v;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }
    dfs(0,-1);
	if(a.empty())	printf("-1");
	for(auto x:a)
		printf("%d ",x);
	printf("\n");
	if(b.empty())	printf("-1");
	for(auto x:b)
		printf("%d ",x);
	printf("\n");
	return 0;
}
