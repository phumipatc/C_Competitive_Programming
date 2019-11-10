/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[2010],b[2010],c[2010];
int dp[2010][2010],path[2010][2010];
int main(){
    int lena,lenb,k = 0;
    scanf(" %s %s",a+1,b+1);
    lena = strlen(a+1),lenb = strlen(b+1);
    for(int i=1;i<=lena;i++){
        for(int j=1;j<=lenb;j++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i-1][j-1]+1;
                path[i][j] = 3;
            }else if(dp[i-1][j]>=dp[i][j-1]){
                dp[i][j] = dp[i-1][j];
                path[i][j] = 1;
            }else{
                dp[i][j] = dp[i][j-1];
                path[i][j] = 2;
            }
        }
    }
    printf("%d\n",dp[lena][lenb]);
    if(dp[lena][lenb] == 0){
        printf("No Roma word\n");
        return 0;
    }
    int i = lena,j = lenb;
    while(i>0 && j>0){
        if(path[i][j] == 1)         i--;
        else if(path[i][j] == 2)    j--;
        else{
            c[k++] = a[i];
            i--,j--;
        }
    }
    for(int i=k-1;i>=0;i--)
        printf("%c",c[i]);
	return 0;
}
