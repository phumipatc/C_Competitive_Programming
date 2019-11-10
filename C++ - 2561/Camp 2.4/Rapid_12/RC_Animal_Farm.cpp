/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[2010][2010],dp[2][2010][4010];
int main(){
    int r,c,now,last;
    scanf("%d %d",&r,&c);
    for(long long i=1;i<=r;i++)
        for(long long j=1;j<=c;j++)
            scanf(" %c",&a[i][j]);
    for(int i=1;i<=r;i++){
        now = i%2,last = !now;
        for(int j=1;j<=c;j++){
            if(i-1>0 && j-1>0){
                if(strcmp(dp[last][j],dp[now][j-1])<0){
                    strcpy(dp[now][j],dp[last][j]);
                    dp[now][j][i+j-2] = a[i][j];
                }else{
                    strcpy(dp[now][j],dp[now][j-1]);
                    dp[now][j][i+j-2] = a[i][j];
                }
            }else if(i-1 == 0){
                strcpy(dp[now][j],dp[now][j-1]);
                dp[now][j][i+j-2] = a[i][j];
            }else{
                strcpy(dp[now][j],dp[last][j]);
                dp[now][j][i+j-2] = a[i][j];
            }
            // printf("%s\n",dp[now][j]);
        }
    }
    printf("%s\n",dp[r%2][c]);
	return 0;
}