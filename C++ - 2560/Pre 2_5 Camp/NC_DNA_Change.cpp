/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[10100],golden[5050];
int cost[10],qs[5050],dp[10100][5050];
int main(){
	int lena,lenb,temp,ans=1e9;
	scanf(" %s",str+1);
	scanf(" %s",golden+1);
	lena = strlen(str+1);
	lenb = strlen(golden+1);
	for(int i=1;i<=4;i++)
          scanf("%d",&cost[i]);
	for(int i=1;i<=lenb;i++){
		if(golden[i] == 'A')    qs[i] = qs[i-1] + cost[1];
		if(golden[i] == 'C')	qs[i] = qs[i-1] + cost[2];
		if(golden[i] == 'G')	qs[i] = qs[i-1] + cost[3];
		if(golden[i] == 'T')	qs[i] = qs[i-1] + cost[4];
	}
     for(int j=1;j<=lenb;j++)
        dp[0][j] = qs[j];
     for(int i=1;i<=lena;i++){
		temp = 0;
		for(int j=1;j<=lenb;j++){
            if(str[i] == golden[j])	dp[i][j] = dp[i-1][j-1];
            else                    dp[i][j] = qs[j] + temp;
            temp = min(temp,-qs[j]+dp[i][j]);
		}
     }
     for(int i = 1 ; i <= lena ; i++)
          ans = min(ans,dp[i][lenb]);
     printf("%d\n",ans);
}
