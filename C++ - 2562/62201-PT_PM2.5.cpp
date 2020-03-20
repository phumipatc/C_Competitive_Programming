/*
    TASK:PT_PM2.5
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,w;
};
char a[1010][1010];
int dis[1010][1010],di[]={0,0,-1,1},dj[]={1,-1,0,0};
queue< A > q;
int main()
{
    int n,m,qu,si,sj,ei,ej;
    scanf("%d",&qu);
    while(qu--){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf(" %s",a[i]+1);
        for(int j=1;j<=m;j++){
            if(a[i][j]=='S')si=i,sj=j;
            if(a[i][j]=='E')ei=i,ej=j;
            dis[i][j]=2e9;
        }
    }
    dis[ei][ej]=1;
    int ti,tj,w,ii,jj;
    q.push({ei,ej,1});
    while(!q.empty())
    {
        ti=q.front().i;
        tj=q.front().j;
        w=q.front().w;
        q.pop();
        for(int k=0;k<4;k++){
            ii=ti+di[k];
            jj=tj+dj[k];
            if(ii<1 || ii>n || jj<1 || jj>m) continue;
            if(a[ii][jj]=='#') continue;
            if(dis[ii][jj]<=w+1) continue;
            dis[ii][jj]=w+1;
            q.push({ii,jj,w+1});
        }
    }
    int st=dis[si][sj],ans=0;
    if(st==2e9){printf("-1\n");continue;}
    // printf("%d\n",dis[si][sj]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            // if(dis[i][j]==2e9) printf("0 ");
            // else
            // printf("%d ",dis[i][j]);
            if(a[i][j]=='0') continue;
            if(a[i][j]=='#') continue;
            if(a[i][j]=='S') continue;
            if(a[i][j]=='E') continue;
            // printf("%d\n",dis[i][j]);
            if(dis[i][j]<=dis[si][sj]){ans+=(a[i][j]-'0');}
        }
        // printf("\n");
    }
    printf("%d\n",ans);
    }
    return 0;
}