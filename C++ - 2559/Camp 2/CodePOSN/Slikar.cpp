#include<bits/stdc++.h>
using namespace std;
struct Walk
{
    int x,y,walk;
};
Walk tmp;
int mark[160][160],mark2[160][160];
int water[160][160];
char a[160][160];
int dir[5][3] = {{1,0},{-1,0},{0,1},{0,-1}};
queue<Walk>q;
int main()
{
    int n,m;
    Walk st,ed;
    scanf("%d %d",&n,&m);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            water[i][j] = 100000;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf(" %c",&a[i][j]);
            if(a[i][j] == '*')
                tmp.x = i,tmp.y = j,tmp.walk = 0,q.push(tmp);
            if(a[i][j] == 'S')
                st.x = i,st.y = j,st.walk = 0;
            if(a[i][j] == 'D')
                ed.x = i,ed.y = j;
        }
    }
    while(!q.empty())
    {
        int nowi = q.front().x,nowj = q.front().y,wa = q.front().walk ;
        q.pop();
        if(mark[nowi][nowj] == 1)
            continue;
        mark[nowi][nowj] = 1;
        water[nowi][nowj] = wa;
        for(int i=0;i<4;i++)
        {
            int newi = nowi+dir[i][0];
            int newj = nowj+dir[i][1];
            if(newi < 0 || newi >= n)
                continue;
            if(newj < 0 || newj >= m)
                continue;
            if(a[newi][newj] == 'X'||a[newi][newj]=='D')
                continue;
            tmp.x = newi,tmp.y = newj,tmp.walk = wa+1;
            q.push(tmp);
        }
    }
    st.walk = 0;
    q.push(st);
    while(!q.empty())
    {
        int nowi = q.front().x,nowj = q.front().y,wa = q.front().walk ;
        q.pop();
        if(mark2[nowi][nowj] == 1)
            continue;
        mark2[nowi][nowj] = 1;
        if(a[nowi][nowj] == 'D')
        {
            printf("%d\n",wa);
            return 0;
        }
        for(int i=0;i<4;i++)
        {
            int newi = nowi+dir[i][0];
            int newj = nowj+dir[i][1];
            if(newi < 0 || newi >= n)
                continue;
            if(newj < 0 || newj >= m)
                continue;
            if(a[newi][newj] == 'X')
                continue;
            if(a[newi][newj]!='D' && wa+1 >= water[newi][newj])
                continue;
            tmp.x = newi,tmp.y = newj,tmp.walk = wa+1;
            q.push(tmp);
        }
    }
    printf("KAKTUS\n");
    return 0;
}
/*
5 5
D....*
.XXXXX
......
.....S
......
*/
