/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[1000010];
queue<int > que;
int color[1000010],temp[2010];
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
            if(color[x])    continue;
            for(auto y:g[x]){
                temp[color[y]] = 1;
            }
            for(int i=1;i<=2000;i++){
                if(temp[i] == 0){
                    color[x] = i;
                    break;
                }
            }
            memset(temp,0,sizeof temp);
            que.push(x);
          }
    }
    for(int i=1;i<=1000000;i++){
        if(!g[i].size())    continue;
        printf("%d\n",color[i]);
    }
	return 0;
}
