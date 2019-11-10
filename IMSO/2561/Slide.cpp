/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[110][110],dp[110][110][110];
int main(){
	freopen("0_in.txt","r",stdin);
	freopen("0_out.txt","w",stdout);
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=(2*i)-1;j++){
			scanf("%d",&a[i][j]);
		}
	}
	return 0;
}
