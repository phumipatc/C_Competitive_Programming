/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int mic[510][510][55],a[510][510];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int maxx=-1;
            for(int l=0;l<=k;l++)
                maxx=max(maxx,max(mic[i-1][j][l],mic[i][j-1][l]));
            mic[i][j][0]=maxx;
            for(int l=1;l<=k;l++)
                mic[i][j][l]=a[i][j]+max(mic[i-1][j][l-1],mic[i][j-1][l-1]);
        }
    }
    int maxx=-1;
    for(int i=0;i<=k;i++)
        maxx=max(maxx,mic[n][n][i]);
    printf("%d\n",maxx);
    return 0;
}
