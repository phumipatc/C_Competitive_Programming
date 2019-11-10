/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[300010];
long long last[30],temp[30],ans[30];
int main(){
    long long n,maxx = 0;
    scanf(" %s",str+1);
    n = strlen(str+1);
    for(long long i=1;i<=n;i++){
        last[str[i]-'a'] = i;
        for(long long j=0;j<26;j++)
            temp[j] = -last[j];
        sort(temp,temp+26);
        for(long long j=0;j<26;j++){
            ans[j+1]+=(-temp[j]+temp[j+1]);
            if(ans[j+1])    maxx = max(maxx,j+1);
        }
    }
    printf("%lld\n",maxx);
    for(long long i=1;i<=maxx;i++)
        printf("%lld\n",ans[i]);
	return 0;
}
