#include<bits/stdc++.h>
using namespace std;
struct Mirror
{
    int x,y,rote,di;
};
Mirror st,ed,tmp;
int dir[5][3] = {{-1,0},{0,1},{1,0},{0,-1}};
queue<Mirror>q;
char a[110][110];
int mark[110][110];
int ans[120][120];
int main()
{
    int n,m;
    scanf("%d %d",&m,&n);
    st.di = 0;
    memset(ans,-1,sizeof(ans));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++){
            scanf(" %c",&a[i][j]);
            if(a[i][j]=='M'){
            if(st.di == 0)
                st.di = -1,st.x = i,st.y = j;
            else if(st.di==-1)
                ed.x = i,ed.y = j;
            }
        }
    }
    st.di = -1,st.rote = -1;
    int anss = -5;
    q.push(st);
    while(!q.empty())
    {
        int nowi = q.front().x,nowj = q.front().y,nowdi = q.front().di,rot = q.front().rote;
        q.pop();
        if(nowi < 0 || nowi >= n)
            continue;
        if(nowj < 0 || nowj >= m)
            continue;
        if(a[nowi][nowj]=='*')
            continue;
        if(mark[nowi][nowj]==1&&rot> ans[nowi][nowj])
            continue;
        ans[nowi][nowj] = rot;
        mark[nowi][nowj] = 1;
        for(int i=0;i<4;i++)
        {
            tmp.x = nowi+dir[i][0];
            tmp.y = nowj+dir[i][1];
            tmp.di = i;
            if(tmp.di != nowdi)
                tmp.rote = rot+1;
            else
                tmp.rote = rot;
            q.push(tmp);
        }
    }
    printf("%d\n",ans[ed.x][ed.y]);
    return 0;
}
