#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>Box;
queue<Box>q;
Box tmp;
int dir[5][3] = {{1,0},{-1,0},{0,1},{0,-1}};
int a[40][40];
int mark[40][40];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf(" %c",&a[i][j]);
    for(int i=1;i<=m;i++)
    {
        if(a[1][i]=='.'&&a[2][i]=='.'&&a[1][i+1]=='.'&&a[2][i+1]=='.')
            tmp.first = 1,tmp.second = i,q.push(tmp);
    }
    while(!q.empty())
    {
        int nowi = q.front().first;
        int nowj = q.front().second;
        q.pop();
        if(mark[nowi][nowj]==1)
            continue;
        mark[nowi][nowj] = 1;
        if(nowi==n-1)
        {
            printf("yes\n");
            return 0;
        }
        for(int k =0;k<4;k++)
        {
            int i = nowi + dir[k][0];
            int j = nowj + dir[k][1];
            if(a[i][j]=='.'&&a[i+1][j]=='.'&&a[i][j+1]=='.'&&a[i+1][j+1]=='.')
                tmp.first = i,tmp.second = j,q.push(tmp);
        }
    }
    printf("no\n");
    return 0;
}
