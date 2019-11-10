#include<bits/stdc++.h>
using namespace std;
char normal[10100];
char want[5050];
int price[10];
int qs[5050];
//a-c-t-g
int dp[10100][5050];
int main(){
	int lenN,lenW;
	scanf(" %s",normal+1);
	scanf(" %s",want+1);
	lenN = strlen(normal+1);
	lenW = strlen(want+1);
	for(int i = 1 ; i <= 4 ; i++){
          scanf("%d",&price[i]);
	}
	for(int i = 1 ; i <= lenW ; i++){
		if(want[i] == 'A')  	qs[i] = qs[i-1] + price[1];
		if(want[i] == 'C')	qs[i] = qs[i-1] + price[2];
		if(want[i] == 'G')	qs[i] = qs[i-1] + price[3];
		if(want[i] == 'T')	qs[i] = qs[i-1] + price[4];
	}
     for(int j = 1 ; j <= lenW ; j++){
          dp[0][j] = qs[j];
     }
     int best;
     for(int i = 1 ; i <= lenN ; i++){
		best = 0;
		for(int j = 1 ; j <= lenW ; j++){
               if(normal[i] == want[j])	dp[i][j] = dp[i-1][j-1];
               else{
				dp[i][j] = qs[j] + best;
               }
               best = min(best,-qs[j]+dp[i][j]);
		}
     }
     int ans = 1e9;
     for(int i = 1 ; i <= lenN ; i++){
          ans = min(ans,dp[i][lenW]);
     }
     printf("%d",ans);
}
