/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w;
};
A a[5010];
int dis[210][210];
int main(){
    int q,n,m,u,v,w;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i == j)  dis[i][j] = 0;
                else        dis[i][j] = 1e9;
            }
        }
        while(m--){
            scanf("%d %d %d",&u,&v,&w);
            dis[u][v] = dis[v][u] = min(w,dis[u][v]);
        }
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    if(dis[i][j]>dis[i][k]+dis[k][j])
                        dis[i][j] = dis[i][k]+dis[k][j];
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
            scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].w);
        int ch;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                ch = 1;
                for(int k=1;k<=m;k++){
                    int st = a[k].u,en = a[k].v;
                    if(min(dis[st][en],min(dis[st][i]+dis[j][en],dis[st][j]+dis[i][en]))!=a[k].w){
                        ch = 0;
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
