/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int component_number[100100],number;
vector<int> g[100100],gt[100100];
stack<int> s;
bool mark[100100];
void dfs(int u){
    if(mark[u]) return ;
    mark[u]=true;
    for(int i=0;i<g[u].size();i++)
        if(!mark[g[u][i]])  dfs(g[u][i]);
    s.push(u);
}
void dfs2(int u){
    if(mark[u]) return ;
    mark[u]=true;
    component_number[u]=number;
    for(int i=0;i<gt[u].size();i++)
        if(!mark[gt[u][i]])    dfs2(gt[u][i]);
}
int main()
{
    int i,n,m,k,t,v,a,b;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&t);
        while(t--){
            scanf("%d",&v);
            g[i].push_back(v);
            gt[v].push_back(i);
        }
    }
    for(i=1;i<=n;i++)   dfs(i);
    for(i=1;i<=n;i++)   mark[i]=false;
    number=1;
    while(!s.empty()){
        if(!mark[s.top()]){
            dfs2(s.top());
            number++;
        }
        s.pop();
    }
    while(k--){
        scanf("%d %d",&a,&b);
        if(component_number[a]==component_number[b])    printf("yes\n");
        else                                            printf("no\n");
    }
    return 0;
}
/*
4 4 2
2 2 4
1 3
1 1
0
3 1
1 4
*/
