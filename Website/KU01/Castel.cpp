/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: 
	Status	: 
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
int ans[100010];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n;
	for(int i=1,x=3,a=0;i<=100003;i+=x,x+=2,a+=2){
		for(int j=i,y=a+2,state=0,b=a;j<=100003;){
			ans[j] = b;
			// if(j<=25)
			// 	printf("%d %d\n",j,b);
			if(!state)	j+=y,b++,y+=2,state = 1;
			else		j--,b++,state = 0;
		}
	}
	cin >> n;
	cout << ans[n] << '\n';
	return 0;
}