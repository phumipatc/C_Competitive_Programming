/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
double d[1010][1010],dmax,px[1010],py[1010],dp[1010];
int mark[1010];
int main(){
    int n,m,i,j,x,y;
    scanf("%d %d %lf",&n,&m,&dmax);
    for(i=0;i<n;i++)
        scanf("%lf %lf",&px[i],&py[i]);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            d[i][j]=sqrt((px[i]-px[j])*(px[i]-px[j])+(py[i]-py[j])*(py[i]-py[j]));
    for(i=0;i<m;i++){
        scanf("%d %d",&x,&y);
        x--,y--;
        d[x][y]=d[y][x]=0;
    }
    for(i=0;i<n;i++)
        dp[i]=-1;
    dp[0]=0;
    while(mark[n-1]==0){
        x=-1;
        for(i=0;i<n;i++)
            if(mark[i]==0 && dp[i]!=-1 && (x==-1 || dp[i]<dp[x]))
                x=i;
        if(x==-1)
            break;
        mark[x]=1;
        for(i=0;i<n;i++)
            if(mark[i]==0 && d[x][i]<=dmax && (dp[i]==-1 || dp[x]+d[x][i]<dp[i]))
            dp[i]=dp[x]+d[x][i];
    }
    if(mark[n-1]==0)
        printf("-1\n");
    else
        printf("%d\n",(int)(dp[n-1]*1000));
return 0;
}
// 9 3 2.0 0 0 0 1 1 1 2 1 2 2 3 2 3 3 4 1 4 3 1 2 2 3 3 4
