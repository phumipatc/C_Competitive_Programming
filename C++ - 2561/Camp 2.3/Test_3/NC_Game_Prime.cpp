/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > prime;
int mark[500010],dp[500010][2];
int play(int now,int state){
    if(dp[now][state]!=-1)  return dp[now][state];
    if(now == 0)			return dp[now][state] = !state;
	if(now == 1)			return dp[now][state] = state;
	int sum = 0,temp = now;
	vector<int > use;
	for(auto x:prime){
		if(temp%x == 0)		use.push_back(x),sum+=x;
		while(temp%x == 0)	temp/=x;
	}
	if(temp!=1)	use.push_back(temp),sum+=temp;
	// printf("%d %d %d\n",now,state,sum);
	for(auto x:use){
		if(state == 0 && play(sum-x,1))		return dp[now][state] = 1;
		if(state == 1 && !play(sum-x,0))	return dp[now][state] = 0;
	}
    if(state == 0)  return dp[now][state] = 0;
    else            return dp[now][state] = 1;
}
int main(){
    prime.push_back(2);
    mark[2] = 1;
    for(int i=3;i<=500000;i+=2)
        mark[i] = 1;
    for(int i=3;i<=sqrt(500000);i++){
        if(!mark[i])    continue;
        prime.push_back(i);
        for(int j=i*i;j<=500000;j+=i)
            mark[j] = 0;
    }
    memset(dp,-1,sizeof dp);
    int q,n;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        printf(play(n,0)?"1\n":"2\n");
    }
	return 0;
}
