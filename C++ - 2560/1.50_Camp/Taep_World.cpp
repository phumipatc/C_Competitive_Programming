/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long mic[1010][1010],ans[1000100],num;
int main(){
    int i,j,k,r,c,countt=0;
    scanf("%d %d %d",&r,&c,&k);
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            scanf("%lld",&num);
            mic[i][j]=mic[i-1][j]+mic[i][j-1]-mic[i-1][j-1]+num;
        }
    }
    for(i=1;i<=r-k+1;i++)
        for(j=1;j<=c-k+1;j++)
            ans[countt++]=mic[i+k-1][j+k-1]-mic[i-1][j+k-1]-mic[i+k-1][j-1]+mic[i-1][j-1];
    sort(ans,ans+countt);
    printf("%lld ",ans[countt-1]);
    for(i=countt-2;i>=0;i--){
        if(ans[i]!=ans[countt-1]){
            printf("%lld",ans[i]);
            return 0;
        }
    }
return 0;
}
/*
4 6 3
10 2 1 3 2 1
3 5 6 2 3 1
2 3 1 4 12 1
1 2 3 4 5 6
*/
