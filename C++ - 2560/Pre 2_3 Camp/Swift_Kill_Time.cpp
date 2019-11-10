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
A a[5100];
int mic[5100][2100];
int main(){
    int n,m,k,st,en;
    scanf("%d %d %d %d %d",&n,&m,&k,&st,&en);
    for(int i=1;i<=m;i++)
        scanf("%d %d %d %d",&a[i].u,&a[i].v,&a[i].c,&a[i].w);
    memset(mic,-1,sizeof mic);
    mic[st][0]=0;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=m;j++){
            A now=a[j];
            if(mic[now.u][i-now.w]!=-1)
                mic[now.v][i] = max(mic[now.v][i],mic[now.u][i-now.w]+now.c);
            if(mic[now.v][i-now.w]!=-1)
                mic[now.u][i] = max(mic[now.u][i],mic[now.v][i-now.w]+now.c);
        }
    }
    int maxx=-1;
    for(int i=1;i<=k;i++)
        maxx=max(maxx,mic[en][i]);
    if(maxx==-1)
        printf("Impossible\n");
    else
        printf("%d\n",maxx);
    return 0;
}
