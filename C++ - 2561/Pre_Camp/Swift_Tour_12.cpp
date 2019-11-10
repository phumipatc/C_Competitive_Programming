/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dis[110][110][2];
int main(){
    int n,m,u,v;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j][0] = dis[i][j][1] = 1e9;
    for(int i=1;i<=n;i++)
        dis[i][i][0] = 0;
    dis[2][2][1] = 0;
    while(m--){
        scanf("%d %d",&u,&v);
        dis[u][v][0] = 1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j][1] = min(dis[i][j][1],dis[i][k][1]+dis[k][j][1]);
                dis[i][j][1] = min(dis[i][j][1],dis[i][k][1]+dis[k][j][0]);
                dis[i][j][1] = min(dis[i][j][1],dis[i][k][0]+dis[k][j][1]);
                if(i == 2 || j == 2 || k == 2)
                    dis[i][j][1] = min(dis[i][j][1],dis[i][k][0]+dis[k][j][0]);
                dis[i][j][0] = min(dis[i][j][0],dis[i][k][0]+dis[k][j][0]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d %d : %d %d\n",i,j,dis[i][j][0],dis[i][j][1]);
        }
    }
    printf("%d\n",dis[1][1][1]);
	return 0;
}
