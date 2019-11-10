/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
struct A
{
    int st,en,weight;
};
A a[2000];
int dis[2000],temp[2000];
int main()
{
    int n,m,t,i,j,s,k,countt=0;
    scanf("%d %d %d %d",&n,&m,&k,&t);
    for(i=0; i<m; i++){
        scanf("%d %d %d",&a[countt].st,&a[countt].en,&a[countt].weight);
        countt++;
    }
    for(i=0; i<k; i++){
        scanf("%d %d %d",&a[countt].st,&a[countt].en,&a[countt].weight);
        a[countt].weight*=(-1);
        countt++;
    }
    while(t--)
    {
        scanf("%d",&s);
        for(i=1; i<=n; i++)
            dis[i]=INF;
        dis[s]=0;
        for(i=1; i<=n; i++)
            for(j=0; j<m+k; j++)
                if(dis[a[j].st]!=INF && dis[a[j].st]+a[j].weight<dis[a[j].en])
                    dis[a[j].en]=dis[a[j].st]+a[j].weight;
        for(i=1;i<=n;i++)
            temp[i]=dis[i];
        for(j=0; j<m+k; j++)
            if(dis[a[j].st]+a[j].weight<dis[a[j].en])
                dis[a[j].en]=dis[a[j].st]+a[j].weight;
        for(i=1;i<=n;i++){
            if(dis[i]!=temp[i] || dis[i]==INF)
                printf("-1 ");
            else
                printf("%d ",dis[i]);
        }
        printf("\n");
    }
    return 0;
}
/*
10 5 5 5
1 7 8
2 5 1
3 4 7
5 8 4
5 1 11
10 1 6
10 5 3
10 3 1
9 5 10
5 7 2
2
4
6
8
10
*/
