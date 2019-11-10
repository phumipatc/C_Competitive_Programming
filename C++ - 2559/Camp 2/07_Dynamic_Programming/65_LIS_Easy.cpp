/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010],dp[1010],path[1010],ans[1010];
int main(){
    int n,i,j,maxx=0,att=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]),dp[i]=-1;
    dp[1]=1,path[1]=0;
    for(i=1;i<=n;i++){
        for(j=1;j<i;j++){
            if(a[j]<a[i] && (dp[j]+1>dp[i] || dp[i]==-1)){
                dp[i]=dp[j]+1,path[i]=j;
            }
        }
        if(dp[i]==-1)
            dp[i]=1;
        if(dp[i]>maxx)
            maxx=dp[i],att=i;
    }
    printf("%d\n",maxx);
    for(i=0;i<maxx;i++)
        ans[i]=a[att],att=path[att];
    for(i=0;i<maxx;i++)
        printf("%d ",ans[maxx-1-i]);
    printf("\n");
return 0;
}
