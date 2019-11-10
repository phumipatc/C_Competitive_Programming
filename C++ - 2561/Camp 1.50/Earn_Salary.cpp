/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[100100],child[100100];
int add[100100],w[100100];
void dfs(int now){
    for(auto &x:g[now]){
        add[x]+=add[now];
        dfs(x);
    }
    w[now]+=add[now];
}
int main(){
    int n,m,u,v;
    scanf("%d %d",&n,&m);
    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        g[v].push_back(u);
    }
    while(m--){
        scanf("%d %d",&u,&v);
        add[u]+=v;
    }
    dfs(1);
    for(int i=1;i<=n;i++)
        printf("%d\n",w[i]);
	return 0;
}
/*
10 10
5 1
4 2
2 6
8 7
9 3
3 2
6 5
7 6
10 1
9 9
1 1
9 6
1 2
9 8
1 2
4 7
2 9
6 7
2 4
*/
