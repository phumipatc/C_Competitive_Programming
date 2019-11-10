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
A a[1110];
int dis[1010],dis2[1010];
int main(){
    int n,m,k,t,u,v,w,st;
    scanf("%d %d %d %d",&n,&m,&k,&t);
    for(int i=1;i<=m;i++)
        scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].w);
    for(int i=m+1;i<=m+k;i++)
        scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].w),a[i].w*=-1;
    while(t--){
        scanf("%d",&st);
        for(int i=1;i<=n;i++)   dis[i] = 1e9;
        dis[st] = 0;
        for(int i=1;i<n;i++)
            for(int j=1;j<=m+k;j++)
                if(dis[a[j].v]>dis[a[j].u]+a[j].w && dis[a[j].u]!=1e9)
                    dis[a[j].v] = dis[a[j].u]+a[j].w;
        for(int i=1;i<=n;i++)
            dis2[i] = dis[i];
        for(int j=1;j<=m+k;j++)
            if(dis[a[j].v]>dis[a[j].u]+a[j].w)
                dis[a[j].v] = dis[a[j].u]+a[j].w;
        for(int i=1;i<=n;i++){
            if(dis[i] == dis2[i] && dis[i]!=1e9)    printf("%d ",dis[i]);
            else                                    printf("-1 ");
        }
        printf("\n");
    }
	return 0;
}
