/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010][1010];
int main(){
    char b;
    int n,m,i,j,ans=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf(" %c",&b);
            if(b=='#')
                a[i][j] = 0;
            else
                a[i][j] = 1;
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i][j]==1){
                a[i][j] = min(a[i-1][j-1],min(a[i-1][j],a[i][j-1]))+1;
                ans = max(ans,a[i][j]);
            }
        }
    }
    printf("%d",ans);
return 0;
}
