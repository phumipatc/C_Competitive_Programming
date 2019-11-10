/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w,c;
};
A a[5010];
int dis[5010][2010];
int main(){
    int n,m,k,st,en;
    scanf("%d %d %d %d %d",&n,&m,&k,&st,&en);
    for(int i=1;i<=m;i++)
        scanf("%d %d %d %d",&a[i].u,&a[i].v,&a[i].c,&a[i].w);
    memset(dis,-1,sizeof dis);
    dis[st][0] = 0;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=m;j++){
            if(dis[a[j].u][i-a[j].w]!=-1)
                dis[a[j].v][i] = max(dis[a[j].v][i],dis[a[j].u][i-a[j].w]+a[j].c);
            if(dis[a[j].v][i-a[j].w]!=-1)
                dis[a[j].u][i] = max(dis[a[j].u][i],dis[a[j].v][i-a[j].w]+a[j].c);
        }
    }
    int maxx = -1;
    for(int i=1;i<=k;i++)
        maxx = max(maxx,dis[en][i]);
    if(maxx == -1)	printf("Impossible\n");
    else			printf("%d\n",maxx);
    return 0;
}
