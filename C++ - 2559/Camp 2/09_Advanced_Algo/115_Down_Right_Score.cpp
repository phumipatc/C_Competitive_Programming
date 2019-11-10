/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[300][300];
int main(){
    int n,m,i,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            a[i][j]+=max(a[i-1][j],a[i][j-1]);
        }
    }
    printf("%d\n",a[n][m]);
return 0;
}
