#include<bits/stdc++.h>
using namespace std;
int dp[100010][30],mark[30][30];
char b[3],a[100100];
int main(){
    int i,j,q,lena,ma = 1<<30,mi = 1<<30;
    scanf(" %s",a+1);
    lena = strlen(a+1);
    scanf("%d",&q);
    while(q--){
        scanf(" %s",b);
        mark[b[0]-'a'+1][b[1]-'a'+1] = mark[b[1]-'a'+1][b[0]-'a'+1] = 1;
    }
    for(i=0; i<=lena; i++)
        for(j=0; j<=26; j++)
            dp[i][j] = 1<<30;
    dp[0][0] = 0;
    for(i=1; i<=lena; i++){
        for(j=0; j<=26; j++){
            dp[i][j] = min(dp[i][j],dp[i-1][j]+1);
            if(!mark[j][a[i]-'a'+1])
                dp[i][a[i]-'a'+1] = min(dp[i][a[i]-'a'+1],dp[i-1][j]);
        }
    }
    for(i=1; i<=26; i++){
        mi = min(dp[lena][i],mi);
    }
    printf("%d\n",mi);
    return 0;
}
