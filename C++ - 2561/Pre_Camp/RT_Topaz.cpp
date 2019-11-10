/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[55],b[55],c[55],d[55];
long long place[5][55],dp[55][55][55][55],ca[55][55][55][55],num[30];
int main(){
    long long q,lena,lenb,lenc,lend;
    scanf("%lld",&q);
    while(q--){
        scanf("%s %s %s %s",a+1,b+1,c+1,d+1);
        lena = strlen(a+1);
        lenb = strlen(b+1);
        lenc = strlen(c+1);
        lend = strlen(d+1);
        memset(num,0,sizeof num);
        for(long long i=1;i<=lena;i++){
            place[0][i] = num[a[i]-'a'];
            num[a[i]-'a'] = i;
        }
        memset(num,0,sizeof num);
        for(long long i=1;i<=lenb;i++){
            place[1][i] = num[b[i]-'a'];
            num[b[i]-'a'] = i;
        }
        memset(num,0,sizeof num);
        for(long long i=1;i<=lenc;i++){
            place[2][i] = num[c[i]-'a'];
            num[c[i]-'a'] = i;
        }
        memset(num,0,sizeof num);
        for(long long i=1;i<=lend;i++){
            place[3][i] = num[d[i]-'a'];
            num[d[i]-'a'] = i;
        }
        for(long long i=1;i<=lena;i++){
            for(long long j=1;j<=lenb;j++){
                for(long long k=1;k<=lenc;k++){
                    for(long long l=1;l<=lend;l++){
                        if(a[i] == b[j] && b[j] == c[k] && c[k] == d[l]){
                            dp[i][j][k][l] = 2*dp[i-1][j-1][k-1][l-1]+1-ca[place[0][i]][place[1][j]][place[2][k]][place[3][l]];
                            ca[i][j][k][l] = ca[place[0][i]][place[1][j]][place[2][k]][place[3][l]]+(dp[i][j][k][l]-dp[i-1][j-1][k-1][l-1]);
                        }else{
                            dp[i][j][k][l] = dp[i][j-1][k-1][l-1]+dp[i-1][j][k-1][l-1]+dp[i-1][j-1][k][l-1]+dp[i-1][j-1][k-1][l]
                            -dp[i][j][k-1][l-1]-dp[i][j-1][k][l-1]-dp[i][j-1][k-1][l]-dp[i-1][j][k][l-1]-dp[i-1][j][k-1][l]-dp[i-1][j-1][k][l]
                            +dp[i][j][k][l-1]+dp[i][j][k-1][l]+dp[i][j-1][k][l]+dp[i-1][j][k][l]
                            -dp[i-1][j-1][k-1][l-1];
                        }
                    }
                }
            }
        }
        printf("%lld\n",dp[lena][lenb][lenc][lend]);
        memset(place,0,sizeof place);
        memset(dp,0,sizeof dp);
        memset(ca,0,sizeof ca);
    }
	return 0;
}
