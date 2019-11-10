/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
	int taro,tora;
};
A a[100100];
int dp[2][2][110];
int main(){
	freopen("0_in.txt","r",stdin);
	freopen("0_out.txt","w",stdout);
	int q,n,k;
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&n,&k)
		for(int i=1;i<=n;i++)
			scanf("%d %d",&a[i].taro,&a[i].tora);
		for(int i=1;i<=n;i++){
			for(int j=0;j<=k;j++){
			}
		}
		memset(dp,0,sizeof dp);
	}
	return 0;
}
