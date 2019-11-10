/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[101010];
int dis[101010];
queue<int > que;
int main(){
    int n,k,m,temp;
    scanf("%d %d %d",&n,&k,&m);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=k;j++){
            scanf("%d",&temp);
            g[temp].push_back(n+i);
            g[n+i].push_back(temp);
        }
    }
    for(int i=1;i<=n+m;i++)
        dis[i] = 1e9;
    que.push(1);
    dis[1] = 0;
    while(!que.empty()){
        temp = que.front();
        que.pop();
        if(temp == n){
            printf("%d\n",(dis[temp]/2)+1);
            return 0;
        }
        for(auto x:g[temp]){
            if(dis[x]<=dis[temp]+1) continue;
            dis[x] = dis[temp]+1;
            que.push(x);
        }
    }
    printf("-1\n");
	return 0;
}
