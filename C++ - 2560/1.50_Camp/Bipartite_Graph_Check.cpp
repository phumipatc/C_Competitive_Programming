/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector< int> g[100100];
int mark[100100];
int dfs(int u,int color){
    if(mark[u]==color)
        return 1;
    if(mark[u]!=0 && mark[u]!=color)
        return 0;
    mark[u]=color;
    for(int i=0;i<(int)g[u].size();i++){
        if(dfs(g[u][i],3-color)==0)
            return 0;
    }
    return 1;
}
int main()
{
    int q,n,m,r,s,i;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        while(m--){
            scanf("%d %d",&r,&s);
            g[r].push_back(s);
            g[s].push_back(r);
        }
        int ch=1;
        for(i=1;i<=n;i++){
            if(!mark[i]){
                if(dfs(i,1)==0){
                    ch=0;
                    break;
                }
            }
        }
        printf((ch)?"yes\n":"no\n");
        for(i=1;i<=n;i++)
            g[i].clear();
        memset(mark,0,sizeof mark);
    }
	return 0;
}
