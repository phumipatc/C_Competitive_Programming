/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[110],b[100010];
int dp[110][100010];
int main(){
    int lena,lenb,minn = 1e9,ch;
    scanf(" %s %s",a+1,b+1);
    lena = strlen(a+1);
    lenb = strlen(b+1);
    if(lenb<lena){
        printf("RIP ASIA\n");
        return 0;
    }
    for(int i=1;i<=lena;i++)    a[i] = tolower(a[i]);
    for(int i=1;i<=lenb;i++)    b[i] = tolower(b[i]);
    for(int i=1;i<=lena;i++){
        for(int j=1;j<i;j++)    dp[i][j] = -1;
        ch = 0;
        for(int j=i;j<=lenb;j++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i-1][j-1];
                if(dp[i][j] == -1)  continue;
                ch = 1;
            }else if(ch){
                dp[i][j] = dp[i][j-1]+1;
            }else{
                dp[i][j] = -1;
            }
        }
    }
    for(int j=lena;j<=lenb;j++){
        if(a[lena] != b[j])     continue;
        if(dp[lena][j] == -1)   continue;
        minn = min(minn,dp[lena][j]);
    }
    if(minn == 1e9) printf("RIP ASIA\n");
    else            printf("%d\n",minn);
	return 0;
}
