#include<bits/stdc++.h>
using namespace std;
vector<int>a[100100];
int n,m,c;
int ch[100100],mark[100100];
int dfs(int st,int color)
{
    if(mark[st]==1&&ch[st]!=color)
        return 0;
    if(mark[st]==1&&ch[st]==color)
        return 1;
    ch[st] = color;
    mark[st] = 1;
    int siz = a[st].size();
    for(int i=0;i<siz;i++)
        if(dfs(a[st][i],3 - color)==0)
            return 0;
    return 1;
}
int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d",&n,&m);
        while(m--)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            a[u].push_back(v);
            a[v].push_back(u);
        }
        c = dfs(1,1);
        if(c)
            printf("yes\n");
        else
            printf("no\n");
        for(int i=1;i<=n;i++)
            a[i].clear();
        memset(ch,0,sizeof(ch));
        memset(mark,0,sizeof(mark));
    }
    return 0;
}
