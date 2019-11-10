/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[1010];
int in[1010];
queue<int > que;
int main(){
    int n,u,v;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        in[v]++;
    }
    for(int i=0;i<=999;i++){
        if(in[i])           continue;
        if(!g[i].size())    continue;
        que.push(i);
    }
    while(!que.empty()){
        u = que.front();
        que.pop();
        for(auto x:g[u]){
            in[x]--;
            if(in[x])   continue;
            que.push(x);
        }
    }
    for(int i=0;i<=999;i++){
        if(!in[i])  continue;
        printf("BUG\n");
        return 0;
    }
    printf("OK\n");
	return 0;
}
