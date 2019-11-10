/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[500010],b[610];
vector<int > pos[30];
int dp[610][610];
int main(){
    int n,q,lena,lenb,last;
    scanf("%d %d %s",&n,&q,a+1);
    if(n>700)   return 0;
    lena = strlen(a+1);
    for(int i=1;i<=lena;i++)
        pos[a[i]-'A'].push_back(i);
    while(q--){
        scanf(" %s",b+1);
        lenb = strlen(a+1);
        for(int i=1;i<=lena;i++){
            for(int j=1;j<=lenb;j++){
                if(a[i] == b[j])    dp[i][j] = dp[i-1][j-1]+1;
                else                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        printf("%d\n",dp[lena][lenb]);
    }
	return 0;
}