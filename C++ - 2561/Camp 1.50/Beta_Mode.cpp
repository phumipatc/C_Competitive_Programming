/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[10100],b[10100];
int dp[2][10100];
int main(){
    int lena,lenb,en,maxx = 0;
    scanf(" %s %s",a+1,b+1);
    lena = strlen(a+1),lenb = strlen(b+1);
    for(int i=1;i<=lena;i++){
        for(int j=1;j<=lenb;j++){
            if(a[i]!=b[j]){
                dp[i%2][j] = 0;
                continue;
            }
            dp[i%2][j] = dp[(i+1)%2][j-1]+1;
            if(dp[i%2][j]>maxx){
                maxx = dp[i%2][j];
                en = i;
            }
        }
    }
    for(int i=en-maxx+1;i<=en;i++){
        cout << a[i];
    }
	return 0;
}
