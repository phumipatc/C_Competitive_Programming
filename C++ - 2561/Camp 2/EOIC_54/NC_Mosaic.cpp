/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[1000010];
queue<int > que;
int color[1000010],temp[1000010];
int main(){
    int n,m,u,v,now;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=1000000;i++)
        sort(g[i].begin(),g[i].end());
    que.push(1);
    color[1] = 1;
    while(!que.empty()){
        now = que.front();
        que.pop();
        for(auto x:g[now]){
            if(color[x])    temp[color[x]] = 1;
            else            que.push(x);
        }
    }
	return 0;
}
