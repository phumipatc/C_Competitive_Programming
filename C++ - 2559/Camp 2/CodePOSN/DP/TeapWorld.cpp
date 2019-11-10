#include<bits/stdc++.h>
using namespace std;
long long ans1 = 0,ans2 = 0,tmp;
long long a[1110][1110],test;
int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%lld",&a[i][j]);
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }
    for(int i=k;i<=n;i++)
    {
        for(int j=k;j<=m;j++)
        {
            test = a[i][j] - a[i-k][j] - a[i][j-k] + a[i-k][j-k];
            if(test > ans1)
            {
                tmp = ans1;
                ans1 = test;
                ans2 = tmp;
            }
            else if(test != ans1 && test > ans2)
                ans2 = test;
        }
    }
    printf("%lld %lld",ans1,ans2);
    return 0;
}
/*
4 6 3
10 2 1 3 2 1
3 5 6 2 3 1
2 3 1 4 12 1
1 2 3 4 5 6
*/
