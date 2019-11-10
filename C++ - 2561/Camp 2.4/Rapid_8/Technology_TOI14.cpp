/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
priority_queue<A > heap;
vector<int > g[100010];
int lv[100010],dp[100010],in[100010],countt[100010];
void dfs(int now){
    dp[now] = lv[now];
    for(auto x:g[now]){
        if(!dp[x])  dfs(x);
        dp[now] = min(dp[now],dp[x]);
    }
}
int main(){
    int n,k,t,temp,num;
    scanf("%d %d %d",&n,&k,&t);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&lv[i],&temp);
		countt[lv[i]]++;
		in[i] = temp;
        while(temp--){
            scanf("%d",&num);
            g[num].push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(in[i])	continue;
		dfs(i);
		heap.push({i,dp[i]});
    }
	while(!heap.empty() && t--){
		now = heap.top();
		heap.pop();
		countt[lv[now.v]]--;
		for(auto x:g[now.v]){
			in[x]--;
			if(in[x])	continue;
			heap.push({x,dp[x]});
		}
	}
	countt[k+1] = 1e9;
	for(int i=1;i<=k+1;i++){
		if(!countt[i])	continue;
		if(i == 1)	printf("-1\n");
		else		printf("%d\n",i-1);
		break;
	}
	return 0;
}