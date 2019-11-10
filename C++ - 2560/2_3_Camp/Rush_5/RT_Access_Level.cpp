/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int ans[1000100],p[1000100],mark[1010][1010],a[1010][1010],n,m,dir[4]={0,0,1,-1},dic[4]={1,-1,0,0};
int find_root(int i){
    if(p[i]==i) return i;
    else        return p[i]=find_root(p[i]);
}
int dfs(int nowi,int nowj,int last)
{
    int ru,rv,countt=0;
    mark[nowi][nowj]=1;
    if(a[nowi][nowj]==3){
        ru=find_root((nowi-1)*m+nowj);
        rv=find_root(last);
        p[ru]=rv;
    }
    if(a[nowi][nowj]==2)  countt++;
    for(int k=0;k<4;k++)
    {
        int nexti=nowi+dir[k];
        int nextj=nowj+dic[k];
        if(mark[nexti][nextj]==1)   continue;
        if(a[nexti][nextj]==0)      continue;
        if(nexti>n || nextj>m || nexti<=0 || nextj<=0)   continue;
        countt+=dfs(nexti,nextj,last);
    }
    return countt;
}
int main(){
    int i,j,q;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n*m;i++) p[i]=i;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(mark[i][j]==0 && a[i][j]==3)
                ans[(i-1)*m+j]=dfs(i,j,(i-1)*m+j);
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&i,&j);
        int ra=find_root(((i-1)*m)+j);
        printf("%d\n",ans[ra]);
    }
    return 0;
}
/*
10 13
0 1 3 3 0 0 2 0 1 3 0 2 1
0 1 1 1 0 3 1 0 1 0 1 0 3
2 1 2 1 1 3 1 0 0 0 1 0 1
0 0 2 1 2 0 0 1 2 3 0 0 1
1 0 0 1 1 3 0 3 0 3 0 1 1
1 3 0 0 0 2 0 0 1 2 0 1 0
1 0 0 3 0 1 1 0 1 2 0 1 2
0 1 2 2 0 3 1 2 0 1 1 0 1
1 3 3 0 0 1 0 1 0 1 0 1 3
0 0 2 1 0 1 2 0 0 0 0 2 3
10
1 3
1 10
2 13
10 13
9 2
9 13
1 4
3 6
5 10
8 6
*/

