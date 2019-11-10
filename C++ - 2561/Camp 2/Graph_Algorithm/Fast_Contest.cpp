/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
vector <int> g[100100];
vector <int> gt[100100];
queue <int> que;
int dp[100100];
bool mark[100100],limit;
void dfs(int now){
    mark[now]=true;
    for(auto x:g[now]){
        if(!mark[x])
            dfs(x);
    }
    que.push(now);
}
int main()
{
    int n,m,a,b;
    scanf(" %d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf(" %d %d",&a,&b);
        g[a].push_back(b);
        gt[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!mark[i])
            dfs(i);
    }
    dp[2] = 1;
    while(!que.empty()){
        int now=que.front();
        que.pop();
        for(int i=0;i<gt[now].size();i++){
            dp[gt[now][i]]+=dp[now];
            if(dp[gt[now][i]]>=1000000000)  limit = true;
            dp[gt[now][i]]%=1000000000;
        }
    }
    if(limit)
        printf("%09d",dp[1]);
    else
        printf("%d\n",dp[1]);
    return 0;
}

/*
7 10 1
4
1 2 1
1 3 2
4 1 2
2 4 2
3 4 1
4 5 1
4 6 3
5 7 1
7 6 2
4 7 4
-----
4

7 10 2
3 6
1 2 1
1 3 2
4 1 2
2 4 2
3 4 1
4 5 1
4 6 3
5 7 1
7 6 2
4 7 4
-----
8
*/
