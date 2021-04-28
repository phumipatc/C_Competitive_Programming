/*
	Author	: Phumipat C. [MAGCARI] feat. Wasrek, Aphrodicez
	School	: RYW
	Language: C++
	Algo	: Observe
	Status	: Finished
*/
#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define allst(x,y) (x).begin()+y,(x).end()
#define MOD (LL )(1e9+7)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
const int MAX_INT = 1e9;
const LL MAX_LL = 1e18;
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
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
int fib[40];
void init(){
	fib[1] = fib[2] = 1;
	for(int i=3;i<=38;i++)
		fib[i] = fib[i-1] + fib[i-2];
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,h,v;
	cin >> n;
	init();
	h = v = 0;
	for(int i=1;i<=n;i++){
		h+=((((i+1)/2)%2)?1:-1)*fib[i];
		if(((i+1)/2)%2)	v+=((i%2)?-1:1)*fib[i];
		else			v+=((i%2)?1:-1)*fib[i];
	}
	cout << max(v,0) << ' ' << -min(h,0) << ' ' << -min(v,0) << ' ' << max(h,0) << '\n';
	return 0;
}