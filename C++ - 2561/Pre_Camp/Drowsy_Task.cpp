/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[100010],a,b;
long long mark[30][30],dp[30];
int main(){
    long long k,i,j;
    scanf(" %s %lld",str,&k);
    long long len = strlen(str);
    for(i=0;i<k;i++){
        scanf(" %c %c",&a,&b);
        mark[b-'a'][a-'a'] = mark[a-'a'][b-'a'] = 1;
    }
    for(i=0;i<len;i++){
        long long temp = dp[str[i]-'a'];
        for(j=0;j<26;j++)
            if(mark[str[i]-'a'][j] == 0 && str[i]-'a'!=j)
                dp[str[i]-'a'] = max(dp[j]+1,dp[str[i]-'a']);
        dp[str[i]-'a'] = max(dp[str[i]-'a'],temp+1);
    }
    long long ans = 1e9;
    for(i=0;i<len;i++)
        ans = min(ans,len-dp[str[i]-'a']);
    printf("%lld\n",ans);
    return 0;
}
