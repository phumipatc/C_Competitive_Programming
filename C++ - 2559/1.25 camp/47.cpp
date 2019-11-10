/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<cstdio>
#include<algorithm>
using namespace std;
int a[1100][1100],row[1100],col[1100];
int main()
{
    int n,m,i,j,Max,q;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(i=1;i<=n;i++){
            Max=-1;
        for(j=1;j<=m;j++)
            if(a[i][j]>Max)
                Max=a[i][j];
        row[i]=Max;
    }
    for(j=1;j<=m;j++){
            Max=-1;
        for(i=1;i<=n;i++)
            if(a[i][j]>Max)
                Max=a[i][j];
        col[j]=Max;
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&i,&j);
        if(i>n || i<1 || j>m || j<1)
            printf("-1\n");
        else
            printf("%d\n",max(row[i],col[j]));
    }
return 0;
}
