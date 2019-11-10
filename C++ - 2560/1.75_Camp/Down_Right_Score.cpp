/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[300][300];
int main()
{
    int n,m,i,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(j=2;j<=m;j++)
        a[1][j]+=a[1][j-1];
    for(i=2;i<=n;i++)
        a[i][1]+=a[i-1][1];
    for(i=2;i<=n;i++){
        for(j=2;j<=m;j++){
            a[i][j]+=max(a[i-1][j],a[i][j-1]);
        }
    }
    printf("%d\n",a[n][m]);
    return 0;
}
/*
3 3
5 19 47
75 3 1
4 5 24
*/
