/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,t;
};
A now;
char temp;
vector<A > g[110][110];
int ti[110][110];
queue<A > que;
int main(){
    int r,c;
    scanf("%d %d",&r,&c);
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            scanf(" %c",&temp);
            if(temp == 'B'){
                g[i][j].push_back({i+1,j,0});
                g[i][j].push_back({i,j+1,0});
                g[i+1][j].push_back({i,j,0});
                g[i][j+1].push_back({i,j,0});
            }else if(temp == 'R'){
                g[i][j].push_back({i,j+1,0});
                g[i][j+1].push_back({i,j,0});
            }else if(temp == 'D'){
                g[i][j].push_back({i+1,j,0});
                g[i+1][j].push_back({i,j,0});
            }
        }
    }
    que.push({1,1,1});
    ti[1][1] = 1;
    while(!que.empty()){
        now = que.front();
        que.pop();
        for(auto x:g[now.i][now.j]){
            if(ti[x.i][x.j]){
                if(ti[x.i][x.j] == now.t+1){
                    printf("%d\n%d %d\n",now.t+1,x.i,x.j);
                    return 0;
                }else{
                    continue;
                }
            }
            ti[x.i][x.j] = now.t+1;
            que.push({x.i,x.j,now.t+1});
        }
    }
	return 0;
}
