/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[100010];
int deg[100010],lift[100010][20],level[100010];
queue<int > que;
int main(){
    int n,u,v,q;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        deg[v]++;
    }
    for(int i=1;i<=n;i++){
        if(deg[i])  continue;
        level[i] = 1;
        for(auto x:g[i]){
            lift[x][0] = i;
            level[x] = level[i]+1;
            que.push(x);
        }
        break;
    }
    while(!que.empty()){
        u = que.front();
        que.pop();
        for(int i=1;i<=log2(n);i++){
            lift[u][i] = lift[lift[u][0]][i-1];
        }
        for(auto x:g[u]){
            lift[x][0] = u;
            level[x] = level[u]+1;
            que.push(x);
        }
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&u,&v);
        while(level[u]!=level[v]){
            if(level[u]>level[v]){
                for(int i=log2(n);i>=0;i--){
                    if(level[lift[u][i]]>=level[v]){
                        u = lift[u][i];
                        break;
                    }
                }
            }else if(level[v]>level[u]){
                for(int i=log2(n);i>=0;i--){
                    if(level[lift[v][i]]>=level[u]){
                        v = lift[v][i];
                        break;
                    }
                }
            }
        }
        while(u!=v){
            for(int i=log2(n);i>=0;i--){
                if(lift[u][i] == lift[v][i] && i>0) continue;
                u = lift[u][i];
                v = lift[v][i];
                break;
            }
        }
        printf("%d\n",u);
    }
	return 0;
}
