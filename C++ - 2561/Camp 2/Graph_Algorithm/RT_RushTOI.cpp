/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dis[310][310];
int main(){
    int n,m,u,v,w;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j] = 1e9;
    while(m--){
        scanf("%d %d %d",&u,&v,&w);
        dis[u][v] = min(dis[u][v],w);
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][j]>dis[i][k]+dis[k][j]){
                    dis[i][j] = dis[i][k]+dis[k][j];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dis[i][j] == 1e9)    printf("0 ");
            else                    printf("%d ",dis[i][j]);
        }
        printf("\n");
    }
	return 0;
}
