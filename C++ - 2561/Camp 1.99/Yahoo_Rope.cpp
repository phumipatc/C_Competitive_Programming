/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1200],LIS[1200],dp[1200];
int main()
{
    int q,n,i,maxx,idx,t,m;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        m = 0,maxx = -1;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++){
            idx = upper_bound(LIS,LIS+m,a[i])-LIS;
            if(idx>=1 && LIS[idx-1] == a[i]){
                dp[i] = m;
                continue;
            }
            if(m==idx)  m++;
            LIS[idx] = a[i];
            dp[i] = m;
        }
        m = 0;
        memset(LIS,0,sizeof LIS);
        for(i=n-1;i>=0;i--){
            idx = upper_bound(LIS,LIS+m,a[i])-LIS;
            if(idx>=1 && LIS[idx-1]==a[i]){
                maxx = max(maxx,dp[i]+m);
                continue;
            }
            if(m == idx)    m++;
            LIS[idx] = a[i];
            maxx = max(maxx,dp[i]+m);
        }
        printf("%d\n",maxx-1);
        memset(LIS,0,sizeof LIS);
    }
    return 0;
}
/*
1
18
0 2 8 4 3 2 4 1 8 5 7 1 3 9 6 4 2 0
*/
