#include<bits/stdc++.h>
using namespace std;
struct A
{
    int i,j,ty;
};
queue< A > q[2];
char a[705][705];
int mark[705][705],di[]={0,0,-1,1},dj[]={-1,1,0,0};
vector < pair<int,int> > g[490005];
int main()
{
    int z,r,c,i,j,k,l,n,t,si,sj,ch,b,coun,nw,nx,ty,ni,nj;
    scanf("%d",&z);
    while(z--)
    {
        scanf("%d %d %d %d %d %d",&r,&c,&n,&t,&si,&sj);
        while(n--)
        {
            scanf("%d %d %d",&b,&i,&j);
            g[b].push_back({i,j});
        }
        for(i=0;i<r;i++)
            scanf(" %s",a[i]);
        memset(mark,0,sizeof(mark));
        for(i=0;i<g[0].size();i++)
        {
            q[0].push({g[0][i].first,g[0][i].second,1});
            mark[g[0][i].first][g[0][i].second]=2;
        }
        if(mark[si][sj])
        {
            printf("NO -1\n");
            for(i=0;i<=490000;i++)
                g[i].clear();
            while(!q[0].empty())
                q[0].pop();
            continue ;
        }
        q[0].push({si,sj,0});
        mark[si][sj]=1;
        coun=1;
        ch=0;
        for(l=0;l<t;l++)
        {
            nw=l&1;
            nx=(l+1)&1;
            for(i=0;i<g[l+1].size();i++)
            {
                q[nx].push({g[l+1][i].first,g[l+1][i].second,1});
                if(mark[g[l+1][i].first][g[l+1][i].second]==1)
                    coun--;
                mark[g[l+1][i].first][g[l+1][i].second]=2;
            }
            while(!q[nw].empty())
            {
                i=q[nw].front().i;
                j=q[nw].front().j;
                ty=q[nw].front().ty;
                q[nw].pop();
                for(k=0;k<4;k++)
                {
                    ni=i+di[k];
                    nj=j+dj[k];
                    if(ni<0 || nj<0 || ni>=r || nj>=c)
                        continue ;
                    if(a[ni][nj]=='#')
                        continue ;
                    if(ty==0&&mark[ni][nj])
                        continue ;
                    if(ty==1&&mark[ni][nj]==2)
                        continue ;
                    if(ty==1&&mark[ni][nj]==1)
                        coun--;
                    mark[ni][nj]=ty+1;
                    coun+=ty==0;
                    q[nx].push({ni,nj,ty});
                }
            }
            if(coun==0)
            {
                printf("NO %d\n",l);
                ch=1;
                break ;
            }
        }
        if(!ch)
            printf("YES\n");
        for(i=0;i<=490000;i++)
            g[i].clear();
        while(!q[0].empty())
            q[0].pop();
        while(!q[1].empty())
            q[1].pop();
    }
    return 0;
}
/*
4
2 5 1 1 0 2
1 0 2
.....
.....
2 5 1 1 0 2
0 0 2
.....
.....
2 5 4 1 0 2
1 0 2
1 0 3
1 0 1
1 1 2
.....
.....
5 5 2 10 2 2
0 0 0
0 4 4
.....
.###.
.#.#.
.###.
.....
*/
