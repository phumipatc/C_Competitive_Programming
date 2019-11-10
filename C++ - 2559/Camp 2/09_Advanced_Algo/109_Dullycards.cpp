/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[10005][10005],b[10100];
int main(){
    long long ans=0;
    int n,k,i,j;
    a[0][0]=1;
    for(i=1;i<=10000;i++){
        a[i][0]=a[i][i]=1;
        for(j=1;j<i;j++)
            a[i][j]=(a[i-1][j-1]+a[i-1][j])%1000000007;
    }
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%d",&b[i]);
    sort(b,b+n,greater<int>());
    for(i=0;i<n-k+1;i++){
        ans+=(long long)b[i]*a[n-i-1][k-1];
        ans%=1000000007;
    }
    printf("%lld\n",ans);
return 0;
}
