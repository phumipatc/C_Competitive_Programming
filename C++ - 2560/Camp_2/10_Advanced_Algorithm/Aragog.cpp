/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010];
int main()
{
    int q,n,i,j,m,sum,r,s;
    scanf("%d",&q);
    for(i=1;i<=q;i++){
        scanf("%d %d",&n,&m);
        for(j=0;j<n;j++)
            scanf("%d",&a[j]);
    sum=0;
    for(r=0;r<n;r++)
        for(s=r+1;s<n;s++)
            if(a[r]>a[s])   sum++;
    printf("Case %d: ",i);
    if(sum<=m && (m-sum)%2==0)  printf("YES\n");
    else        printf("NO\n");
    }
    return 0;
}
