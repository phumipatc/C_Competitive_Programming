/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[1010],str2[1010];
int dp[1010][1010];
int main(){
    int q,lena,lenb;
    scanf("%d",&q);
    while(q--){
        scanf(" %s %s",str+1,str2+1);
        lena=strlen(str+1);
        lenb=strlen(str2+1);
        for(int i=1;i<=lena;i++)
            dp[i][0] = i;
        for(int i=1;i<=lenb;i++)
            dp[0][i] = i;
        for(int i=1;i<=lena;i++){
            for(int j=1;j<=lenb;j++){
                if(str[i] == str2[j])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            }
        }
        printf("%d\n",dp[lena][lenb]);
    }
    return 0;
}
