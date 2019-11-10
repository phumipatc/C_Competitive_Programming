/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int mem[1510][1510],a[1510][1510],n;
int dp(int l,int r)
{
    if(r==n||l==n)                      return 0;
    if(mem[l][r]!=-1 || mem[r][l]!=-1)  return mem[l][r];
    int next = max(l,r)+1;
    return mem[l][r]=mem[r][l]=min(a[next][l]+dp(next,r),a[r][next]+dp(l,next));
}
int main()
{
    memset(mem,-1,sizeof mem);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    printf("%d\n",dp(1,1));
    return 0;
}
/*
3
0 6 2
6 0 4
2 4 0
*/

