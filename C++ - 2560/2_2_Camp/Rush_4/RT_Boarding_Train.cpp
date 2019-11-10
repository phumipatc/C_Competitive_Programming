/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[20];
char str[30];
int dis[110];
int main(){
    int c,n,m,a,i,j,k,l;
    scanf("%d %d",&c,&n);
    for(i=1;i<=n;i++)   g[1].push_back(i);
    for(i=2;i<=c;i++){
        scanf(" %s %d",str,&m);
        for(j=1;j<=m;j++){
            scanf("%d",&a);
            g[i].push_back(a);
        }
    }
    for(i=1;i<=n;i++)   dis[i]=1e9;
    dis[1]=0;
    for(k=1;k<=n;k++)
        for(i=1;i<=c;i++)
            for(j=1;j<g[i].size();j++)
                dis[g[i][j]]=min(dis[g[i][j]],dis[g[i][j-1]]+1);
//    for(i=1;i<=n;i++)
//        printf("%d ",dis[i]);
    printf("%d\n",dis[n]);
    return 0;
}
/*
4 10
Rapid 5 1 2 5 8 10
Express 3 3 6 9
LtdExpress 3 3 5 10
*/
