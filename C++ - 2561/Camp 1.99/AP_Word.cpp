/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[5010][5010];
char a[5010],b[5010];
int main(){
    int q,lena,lenb;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %s %s",&lena,&lenb,a+1,b+1);
        for(int i=1;i<=lena;i++){
            for(int j=1;j<=lenb;j++){
                if(a[i] == b[j])    dp[i][j] = dp[i-1][j-1]+1;
                else                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        printf("%d\n",lena+lenb-dp[lena][lenb]);
    }
	return 0;
}
