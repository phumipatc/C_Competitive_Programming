#include<bits/stdc++.h>
using namespace std;
priority_queue< pair< int,pair< int,int> > > q;
pair< int,pair< int,int> > temp;
char a[110][110],b[110][110];
int d[8][2]={{-1,-1},{-1,1},{-1,0},{0,-1},{0,1},{1,-1},{1,1},{1,0}};
int main()
{
    int Q,r,c,i,j,h,x,y,z,minn,nextx,nexty,k,w;
    scanf("%d",&Q);
    while(Q--){
        h=0,minn=-1;
        scanf("%d %d",&r,&c);
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                scanf(" %c",&a[i][j]);
                if(a[i][j] != '#' && a[i][j]-'0'>h)
                    h=a[i][j]-'0';
            }
        }
        scanf("%d %d",&x,&y);
        temp.first=0;
        temp.second.first=x,temp.second.second=y;
        q.push(temp);
        while(!q.empty()){
            x=q.top().second.first,y=q.top().second.second;
            z=q.top().first;
            q.pop();
            if(b[x][y]==0){
                if(a[x][y]-'0'==h)
                    minn=0-z;
                b[x][y]=1;
                for(k=0;k<8;k++){
                    nextx=x+d[k][0],nexty=y+d[k][1];
                    if(nextx<0 || nexty<0 || nextx>=r || nexty>=c)
                        continue;
                    if(a[nextx][nexty]=='#')
                        continue;
                    w=abs((a[x][y]-'0')-(a[nextx][nexty]-'0'))+1;
                    w=w*w;
                    temp.first=z-w;
                    temp.second.first=nextx,temp.second.second=nexty;
                    q.push(temp);
                }
            }
        }
        if(minn==-1)
            printf("NO\n");
        else
            printf("%d\n",minn);
        memset(b,0,sizeof b);
    }
    return 0;
}
