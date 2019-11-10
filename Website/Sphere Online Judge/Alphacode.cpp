/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[5100];
int dp[5100];
int main(){
    int len,num;
    scanf(" %s",str+1);
    dp[0] = dp[1] = 1;
    while(str[1]!='0'){
        len = strlen(str+1);
        for(int i=2;i<=len;i++){
            if(str[i]!='0') dp[i]+=dp[i-1];
            if(str[i-1]=='0')   continue;
            num = ((str[i-1]-'0')*10)+(str[i]-'0');
            if(num<=26) dp[i]+=dp[i-2];
        }
        printf("%d\n",dp[len]);
        scanf(" %s",str+1);
        for(int i=2;i<=len;i++) dp[i] = 0;
    }
    return 0;
}
