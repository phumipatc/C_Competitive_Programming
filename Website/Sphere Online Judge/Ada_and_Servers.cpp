/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[610];
int mark[610];
queue<int> que;
int main(){
    int n,m,u,v,countt = 0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        if(mark[i]) continue;
        countt++;
        que.push(i);
        while(!que.empty()){
            int now = que.front();
            que.pop();
            for(auto &x:g[now]){
                if(mark[x]) continue;
                mark[x] = 1;
                que.push(x);
            }
        }
    }
    printf("%d\n",countt);
    return 0;
}
