/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010],b[1010];
int dp[2][1010];
stack<char > st;
int main(){
    int len,maxx = -1e9,en;
    scanf(" %s",a+1);
    len = strlen(a+1);
    for(int i=1;i<=len;i++)
        b[i] = a[len-i+1];
    for(int i=1;i<=len;i++){
        for(int j=1;j<=len;j++){
            if(a[i] == b[j]){
                dp[i%2][j] = dp[(i-1)%2][j-1]+1;
                if(maxx<dp[i%2][j]){
                    maxx = dp[i%2][j];
                    en = i;
                }
            }
        }
    }
    while(maxx--){
        printf("%c",a[en]);
        en--;
    }
	return 0;
}
