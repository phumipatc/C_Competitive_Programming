/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int dis[300][300],s[5100],e[5100],d[5100];
int main()
{
    int q,n,m,a,b,c,st,en,i,j,k,p,ch;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(i==j)    dis[i][j]=0;
                else        dis[i][j]=1e9;
        for(i=1;i<=m;i++){
            scanf("%d %d %d",&a,&b,&c);
            dis[a][b]=dis[b][a]=c;
        }
        for(k=1;k<=n;k++)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        scanf("%d",&p);
        for(i=0;i<p;i++)
            scanf("%d %d %d",&s[i],&e[i],&d[i]);
        for(i=1;i<n;i++){
            for(j=i+1;j<=n;j++){
                ch=1;
                for(k=0;k<p;k++){
                    st=s[k],en=e[k];
                    if(min(dis[st][en],min(dis[st][i]+dis[j][en],dis[st][j]+dis[i][en]))!=d[k]){
                        ch=0;
                        break;
                    }
                }
                if(ch){
                    printf("%d %d",i,j);
                    goto next;
                }
            }
        }
        next :;
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
4 5
1 2 1
2 3 2
3 4 3
4 1 7
2 4 5
1
2 4 4
*/
