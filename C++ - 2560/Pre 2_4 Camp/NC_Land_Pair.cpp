/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MID 2500000
using namespace std;
int countt[5000001],dp[51][51];
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> dp[i][j];
            dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            //left - right
            for(int k=1;k<=i;k++){
                for(int l=1;l<=j;l++){
                    int v=dp[i][j]-dp[k-1][j]-dp[i][l-1]+dp[k-1][l-1];
                    countt[v+MID]++;
                }
            }
            for(int k=i+1;k<=n;k++){
                for(int l=j+1;l<=n;l++){
                    int v=dp[k][l]-dp[k][j]-dp[i][l]+dp[i][j];
                    ans+=countt[v+MID];
                }
            }
            //reset
            for(int k=1;k<=i;k++){
                for(int l=1;l<=j;l++){
                    int v=dp[i][j]-dp[k-1][j]-dp[i][l-1]+dp[k-1][l-1];
                    countt[v+MID]=0;
                }
            }
            //right - left
            for(int k=i;k>=1;k--){
                for(int l=j;l<=n;l++){
                    int v=dp[i][l]-dp[k-1][l]-dp[i][j-1]+dp[k-1][j-1];
                    countt[v+MID]++;
                }
            }
            for(int k=i+1;k<=n;k++){
                for(int l=j-1;l>=1;l--){
                    int v=dp[k][j-1]-dp[i][j-1]-dp[k][l-1]+dp[i][l-1];
                    ans+=countt[v+MID];
                }
            }
            //reset
            for(int k=i;k>=1;k--){
                for(int l=j;l<=n;l++){
                    int v=dp[i][l]-dp[k-1][l]-dp[i][j-1]+dp[k-1][j-1];
                    countt[v+MID]=0;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
