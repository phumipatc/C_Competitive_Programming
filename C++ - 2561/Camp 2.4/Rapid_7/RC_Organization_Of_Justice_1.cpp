/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[200010];
queue<int > que;
int dis[200010];
int main(){
    int n,m,temp,num;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&temp);
        while(temp--){
            scanf("%d",&num);
            g[num].push_back(i+n);
            g[i+n].push_back(num);

            
        }
    }
    int q,st,en;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&st,&en);
        for(int i=1;i<=n+m;i++)
            dis[i] = 1e9;
        dis[st] = 0;
        que.push(st);
        while(!que.empty()){
            int now = que.front();
            que.pop();
            if(now == en){
                printf("%d\n",dis[en]/2);
                break;
            }
            for(auto x:g[now]){
                if(dis[x]!=1e9) continue;
                dis[x] = dis[now]+1;
                que.push(x);
            }
        }
        while(!que.empty()) que.pop();
    }
	return 0;
}
/*
9 3
4 1 2 3 4
3 4 5 6
4 6 7 8 9
4
1 9
2 7
4 1
2 5
*/