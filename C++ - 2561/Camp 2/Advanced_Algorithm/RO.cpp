/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
map<long long ,long long > mapp;
int main(){
    long long n,k,countt = 0,ans = 0;
    char temp;
    scanf("%lld %lld",&n,&k);
    for(long long i=1;i<=n;i++){
        scanf(" %c",&temp);
        if(temp == 'O') countt++;
        else            countt-=k;
        if(mapp[countt])    ans = max(ans,i-mapp[countt]);
        else                mapp[countt] = i;
    }
    printf("%lld\n",ans);
	return 0;
}
