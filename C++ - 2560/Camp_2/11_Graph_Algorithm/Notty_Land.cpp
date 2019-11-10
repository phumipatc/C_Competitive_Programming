/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,k,c,a,b,compnum[100100],nowcomp=1;
vector< int> g[100100];
vector< int> gt[100100];
stack< int> s;
bool visited[100100];
void dfs(int now){
    if(visited[now])    return ;
    visited[now]=true;
    for(int i=0;i<g[now].size();i++){
        if(!visited[g[now][i]]) dfs(g[now][i]);
    }
    s.push(now);
}
void dfs2(int now){
    if(visited[now])    return ;
    visited[now]=true;
    compnum[now]=nowcomp;
    for(int i=0;i<gt[now].size();i++){
        if(!visited[gt[now][i]]) dfs2(gt[now][i]);
    }
}
int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&c);
        for(int j=0;j<c;j++){
            scanf("%d",&a);
            g[i].push_back(a);
            gt[a].push_back(i);
        }
    }
    for(int i=1;i<=n;i++)   dfs(i);
    for(int i=1;i<=n;i++)   visited[i]=false;
    nowcomp=1;
    while(!s.empty()){
        if(!visited[s.top()]){
            dfs2(s.top());
            nowcomp++;
        }
        s.pop();
    }
    while(k--){
        scanf("%d %d",&a,&b);
        if(compnum[a]==compnum[b])  printf("yes\n");
        else                        printf("no\n");
    }
    return 0;
}
