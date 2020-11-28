/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Implement
	Status	: Finished
*/
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
LL minN(vector<LL > a){
	LL minn = 1e18;
	for(auto x:a)
		minn = min(minn,x);
	return minn;
}
LL maxN(vector<LL > a){
	LL maxx = -1e18;
	for(auto x:a)
		maxx = max(maxx,x);
	return maxx;
}
char a[2][1010];
int main(){
	int n,m,dif;
	scanf("%d %d",&m,&n);
	for(int i=1;i<=n;i++){
		scanf(" %s",a[i%2]+1);
		if(i == 1)	continue;
		dif = 0;
		// printf("%s %s\n",a[i&1]+1,a[!(i&1)]+1);
		for(int j=1;j<=m;j++)
			dif+=(a[i&1][j]!=a[!(i&1)][j]);
		if(dif>2){
			printf("%s\n",a[!(i&1)]+1);
			return 0;
		}
	}
	printf("%s\n",a[n&1]+1);
	return 0;
}