/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w;
};
A a[1100];
int dis[1100],temp[1100];
int main()
{
    int n,m,k,t,i,j,st;
    scanf("%d %d %d %d",&n,&m,&k,&t);
    for(i=0;i<m;i++)
        scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].w);
    for(;i<m+k;i++){
        scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].w);
        a[i].w*=(-1);
    }
    while(t--){
        scanf("%d",&st);
        for(i=1;i<=n;i++)   dis[i]=1e9;
        dis[st]=0;
        for(i=1;i<=n;i++)
            for(j=0;j<m+k;j++)
                if(dis[a[j].u]!=1e9 && dis[a[j].u]+a[j].w<dis[a[j].v])
                    dis[a[j].v]=dis[a[j].u]+a[j].w;
        for(i=1;i<=n;i++)   temp[i]=dis[i];
        for(j=0;j<m+k;j++)
            if(dis[a[j].u]+a[j].w<dis[a[j].v])
                dis[a[j].v]=dis[a[j].u]+a[j].w;
        for(i=1;i<=n;i++){
            if(temp[i]!=dis[i] || dis[i]==1e9)  printf("-1 ");
            else                                printf("%d ",dis[i]);
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
*/
