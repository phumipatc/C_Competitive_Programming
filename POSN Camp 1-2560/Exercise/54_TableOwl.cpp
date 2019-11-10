/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[600][600];
int main(){
    int n,i,j,m,minn=1<<30;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(i=n-1;i>0;i--){
        for(j=1;j<=m;j++){
            if(j-1>0 && j+1<=m)
                a[i][j]+=min(a[i+1][j-1],min(a[i+1][j],a[i+1][j+1]));
            else if(j-1>0)
                a[i][j]+=min(a[i+1][j-1],a[i+1][j]);
            else
                a[i][j]+=min(a[i+1][j],a[i+1][j+1]);
        }
    }
    for(j=1;j<=m;j++){
        minn=min(minn,a[1][j]);
    }
    printf("%d",minn);
    return 0;
}
/*
5 6
3 6 1 7 2 3
4 7 9 5 2 1
3 3 3 9 9 8
7 5 7 5 8 9
2 4 1 3 7 1
*/
