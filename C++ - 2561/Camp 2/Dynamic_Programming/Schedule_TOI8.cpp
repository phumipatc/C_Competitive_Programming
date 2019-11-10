/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010],b[1010],dp[1010][1010][2];  //0 = day 1 = hr
int main(){
    int m,n,t1,t2,d1,d2;
    scanf("%d %d",&m,&n);
    dp[0][0][0] = 1;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        dp[i][0][0] = dp[i-1][0][0];
        if(dp[i-1][0][1]+a[i]>m){
            dp[i][0][0]++;
            dp[i][0][1] = a[i];
        }else{
            dp[i][0][1] = dp[i-1][0][1] + a[i];
        }
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        dp[0][i][0] = dp[0][i-1][0];
        if(dp[0][i-1][1]+b[i]>m){
            dp[0][i][0]++;
            dp[0][i][1] = b[i];
        }else{
            dp[0][i][1] = dp[0][i-1][1] + b[i];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            d1 = dp[i-1][j][0];
            if(dp[i-1][j][1]+a[i]>m){
                d1++,t1 = a[i];
            }else{
                t1 = dp[i-1][j][1]+a[i];
            }
            d2 = dp[i][j-1][0];
            if(dp[i][j-1][1]+b[j]>m){
                d2++,t2 = b[j];
            }else{
                t2 = dp[i][j-1][1]+b[j];
            }
            if(d1<d2 || (d1 == d2 && t1<t2)){
                dp[i][j][0] = d1;
                dp[i][j][1] = t1;
            }else{
                dp[i][j][0] = d2;
                dp[i][j][1] = t2;
            }
        }
    }
    printf("%d\n%d\n",dp[n][n][0],dp[n][n][1]);
	return 0;
}
