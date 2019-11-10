/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
map<long long ,long long > mapp;
int main(){
    long long n,st,en,ans = 0,last = 0,sum = 0;
    scanf("%lld",&n);
    while(n--){
        scanf("%lld %lld",&st,&en);
        mapp[st]++,mapp[en+1]--;
    }
    for(auto x:mapp){
        if(sum>1)   ans+=(sum-1)*(x.first-last);
        sum+=x.second;
        last = x.first;
    }
    printf("%lld\n",ans);
	return 0;
}
