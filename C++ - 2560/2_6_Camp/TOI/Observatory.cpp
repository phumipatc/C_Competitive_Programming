/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[2100][2100];
int d[2100][2100],l[2100][2100],r[2100][2100];
int main(){
    int n,m,k,sum,range,ans=-1e18;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            d[i][j]=a[i][j]+d[i-1][j];
            l[i][j]=a[i][j]+l[i-1][j-1];
            r[i][j]=a[i][j]+r[i-1][j+1];
        }
    }
    for(int i=k;i<=n;i++){
        sum=0;
        range=i-k;
        for(int j=1;j<=k;j++,range++)
            sum+=d[i][j]-d[range][j];
        ans=max(ans,sum);
        for(int j=2;j<=m-k+1;j++){
            sum-=(d[i][j-1]-d[i-k][j-1]);
            sum+=(l[i][j+k-1]-l[i-k][j-1]);
            ans=max(ans,sum);
        }
    }
    for(int i=k;i<=n;i++){
        sum=0;
        range=i-k;
        for(int j=m;j>=m-k+1;j--,range++)
            sum+=d[i][j]-d[range][j];
        ans=max(ans,sum);
        for(int j=m-1;j>=k;j--){
            sum-=(d[i][j+1]-d[i-k][j+1]);
            sum+=(r[i][j-k+1]-r[i-k][j+1]);
            ans=max(ans,sum);
        }
    }
    printf("%d\n",ans);
    return 0;
}
