/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[2100][2100],d[2100][2100],l[2100][2100],r[2100][2100];
int main(){
    int m,n,k,i,j,ans=-1e9,value,temp;
    scanf("%d %d %d",&m,&n,&k);
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            d[i][j]=l[i][j]=r[i][j]=a[i][j];
        }
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            d[i][j]+=d[i-1][j];
            l[i][j]+=l[i-1][j-1];
            r[i][j]+=r[i-1][j+1];
        }
    }
    for(i=k;i<=m;i++){
        temp=i-k;
        value=0;
        for(j=1;j<=k;j++,temp++)
            value+=d[i][j]-d[temp][j];
        ans=max(ans,value);
        for(j=2;j<=n-k+1;j++){
            value-=(d[i][j-1]-d[i-k][j-1]);
            value+=(l[i][j+k-1]-l[i-k][j-1]);
            ans=max(ans,value);
        }
    }
    for(i=k;i<=m;i++){
        temp=i-k;
        value=0;
        for(j=n;j>=n-k+1;j--,temp++)
            value+=d[i][j]-d[temp][j];
        ans=max(ans,value);
        for(j=n-1;j>=k;j--){
            value+=(r[i][j-k+1]-r[i-k][j+1]);
            value-=(d[i][j+1]-d[i-k][j+1]);
            ans=max(ans,value);
        }
    }
    printf("%d",ans);
}
/*
4 5 3
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
*/
