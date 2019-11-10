/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010][1010];
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }
    int ans = -1e9;
    for(int i=k;i<=n;i++)
        for(int j=k;j<=m;j++)
            ans = max(ans,a[i][j]-a[i-k][j]-a[i][j-k]+a[i-k][j-k]);
    printf("%d\n",ans);
    return 0;
}
