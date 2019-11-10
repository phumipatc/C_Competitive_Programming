/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector< int> g[50100];
int col[5],mark[50100];
int DFS(int u,int color){
    col[color]++;
    mark[u]=1;
    for(int i=0;i<(int)g[u].size();i++){
        if(!mark[g[u][i]])
            DFS(g[u][i],color^1);
    }
}
int main()
{
    int n,m,r,s,i,ans=0
    ;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&r,&s);
        g[r].push_back(s);
        g[s].push_back(r);
    }
    for(i=1;i<=n;i++){
        if(!mark[i]){
            col[0]=col[1]=0;
            DFS(i,0);
            if(col[0]>col[1])
                swap(col[0],col[1]);
            ans+=(col[0]*3+col[1]);
        }
    }
    printf("%d\n",ans);
	return 0;
}
