/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v;
};
A a[5100];
int mark[1100][1100];
int ans[7];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&a[i].u,&a[i].v);
        mark[a[i].u][a[i].v] = mark[a[i].v][a[i].u] = 1;
    }
    for(int i=1;i<m;i++){
        for(int j=i+1;j<=m;j++){
            if(a[i].u==a[j].u || a[i].u==a[j].v)    continue;
            if(a[i].v==a[j].u || a[i].v==a[j].v)    continue;
            int countt=2;
            if(mark[a[i].u][a[j].u])  countt++;
            if(mark[a[i].u][a[j].v])  countt++;
            if(mark[a[i].v][a[j].u])  countt++;
            if(mark[a[i].v][a[j].v])  countt++;
            if(countt>=5)   ans[countt]++;
        }
    }
    printf("%d\n",(ans[5]/2)+(ans[6]/3));
    return 0;
}
