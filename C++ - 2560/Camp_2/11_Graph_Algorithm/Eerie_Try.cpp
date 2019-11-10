/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int dis[210][210],x[5100],y[5100],d[5100];
int main()
{
    int n,m,i,j,q,a,b,di,k,p,ch,s,e;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(i==j)    dis[i][j]=0;
                else        dis[i][j]=1e9;
        while(m--){
            scanf("%d %d %d",&a,&b,&di);
            dis[a][b]=dis[b][a]=di;
        }
        for(k=1;k<=n;k++)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        scanf("%d",&p);
        for(i=1;i<=p;i++)
            scanf("%d %d %d",&x[i],&y[i],&d[i]);
        for(i=1;i<=n-1;i++){
            for(j=i+1;j<=n;j++){
                ch=1;
                for(k=1;k<=p;k++){
                    s=x[k],e=y[k];
                    if(min(dis[s][e],min(dis[s][i]+dis[j][e],dis[s][j]+dis[i][e]))!=d[k]){
                        ch=0;
                        break;
                    }
                }
                if(ch){
                    printf("%d %d\n",i,j);
                    goto next;
                }
            }
        }
        next: ;
    }
    return 0;
}
/*
2
5 5
1 2 3
2 3 6
2 5 4
3 4 2
3 5 6
2
4 5 7
1 5 7
*/
