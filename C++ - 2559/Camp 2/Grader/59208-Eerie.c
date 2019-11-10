#include<bits/stdc++.h>
using namespace std;
int dist[300][300],x[5050],y[5050],dd[5050];
int main()
{
    int q,m,s,e,i,j,k,n,d,p;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(i==j)    dist[i][j]=0;
                else        dist[i][j]=1000000000;
        while(m--){
            scanf("%d %d %d",&i,&j,&d);
            dist[i][j]=dist[j][i]=d;
        }
        for(k=1;k<=n;k++)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
        scanf("%d",&p);
        for(i=0;i<p;i++)
            scanf("%d %d %d",&x[i],&y[i],&dd[i]);
        for(i=1;i<=n-1;i++){
            for(j=i+1;j<=n;j++){
                for(k=0;k<p;k++){
                    s=x[k],e=y[k];
                    if( min(dist[s][j]+dist[i][e],min(dist[s][e],dist[s][i]+dist[j][e]))!=dd[k])
                        break;
                }
                if(k==p){
                    printf("%d %d\n",i,j);
                    goto comehere;
                    break;
                }
            }
        }
        comehere:;
    }
    return 0;
}
