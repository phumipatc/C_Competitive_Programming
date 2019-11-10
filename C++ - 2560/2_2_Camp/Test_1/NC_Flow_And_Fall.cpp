/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int mem[110][110],a[110][110],d[5][5]={{1,0},{0,1},{-1,0},{0,-1}},n,m;
int flow(int i,int j){
    if(mem[i][j]!=-1)   return mem[i][j];
    int maxx=0;
    for(int k=0;k<4;k++){
        int ni=i+d[k][0];
        int nj=j+d[k][1];
        if(ni < 1 || nj < 1 || ni > n || nj > m || a[ni][nj] <= a[i][j])    continue;
        maxx=max(maxx,flow(ni,nj));
    }
    return mem[i][j]=maxx+1;
}
int main(){
    int i,j,si,sj,maxx=-1,ni,nj;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    memset(mem,-1,sizeof mem);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            maxx = max(maxx,flow(i,j));
    printf("%d\n",maxx);
    return 0;
}
