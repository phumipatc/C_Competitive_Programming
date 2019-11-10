/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int mic[200][10100];
int main(){
    int n,m,p,w,i,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d %d",&p,&w);
        for(j=1;j<=m;j++){
            mic[i][j]=mic[i-1][j];
            if(j>=w)
                mic[i][j]=max(mic[i][j],mic[i-1][j-w]+p);
        }
    }
    printf("%d\n",mic[n][m]);
return 0;
}
