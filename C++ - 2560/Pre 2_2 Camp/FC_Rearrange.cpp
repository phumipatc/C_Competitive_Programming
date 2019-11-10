/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1500005],a[1000005];
int main()
{
    int q,n,m,i,j,ma;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&m,&n);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        dp[0]=1;
        for(i=1;i<=n-1;i++)
            for(j=m;j>=0;j--)
                if(dp[j])
                    dp[j+a[i]]=1;
        for(i=m-1;i>=0;i--)
            if(dp[i])
                break;
        if(m==0)    printf("%d\n",-a[n]);
        else
            printf("%d\n",m-i-a[n]);
        memset(dp,0,sizeof dp);
    }
    return 0;
}
/*
2
5 4
1 2 3 4
100 3
70 60 80
*/
