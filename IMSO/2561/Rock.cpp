/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[110],dp[110][110][2];
int pick(int l,int r,int state){
	if(l>r)				return 0;
	if(dp[l][r][state])	return dp[l][r][state];
	if(state)
		return dp[l][r][state] = max(pick(l+1,r,!state)+a[l],pick(l,r-1,!state)+a[r]);
	else
		return dp[l][r][state] = max(pick(l+1,r,!state),pick(l,r-1,!state));
}
int main(){
	freopen("0_in.txt","r",stdin);
	freopen("0_out.txt","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)
		scanf("%d",&a[i]);
	printf("%d\n",pick(1,2*n,1));
	return 0;
}
