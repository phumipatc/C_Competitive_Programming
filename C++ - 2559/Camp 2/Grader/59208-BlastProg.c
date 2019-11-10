#include<bits/stdc++.h>
using namespace std;
int d[100][100];
int main()
{
    int m,s,e,i,j,k;
    for(i=1;i<=60;i++)
        for(j=1;j<=60;j++)
            d[i][j]=1000000000;
    scanf("%d %d %d",&m,&s,&e);
    while(m--){
        scanf("%d %d",&i,&j);
        d[i][j]=d[j][i]=1;
    }
    for(k=1;k<=60;k++)
        for(i=1;i<=60;i++)
            for(j=i+1;j<=60;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    printf("%d\n",d[s][e]);
    return 0;
}
