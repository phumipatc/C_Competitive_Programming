/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	:
	Status	: Unfinished
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
int a[300010],b[300010];
int check(int now){
	if(a[now]>a[now-1] && a[now]>a[now+1])	return 1;
	if(a[now]<a[now-1] && a[now]<a[now+1])	return 1;
	return 0;
}
void solve(){
	int n,temp,sum = 0,maxx = 0,l,r,now;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	b[1] = b[n] = 0;
	for(int i=2;i<n;i++)
		b[i] = check(i),sum+=b[i];
	for(int i=2;i<n;i++){
		temp = a[i];
		now = b[i],l = b[i-1],r = b[i+1];
		a[i] = a[i-1];
		maxx = max(maxx,now + l + (i+2<=n && r && check(i+1)));
		a[i] = a[i+1];
		maxx = max(maxx,now + r + (i-2>=1 && l && check(i-1)));
		a[i] = 0;
		maxx = max(maxx,now + (i-2>=1 && l && check(i-1)) + (i+2<=n && r && check(i+1)));
		a[i] = 1e9+7;
		maxx = max(maxx,now + (i-2>=1 && l && check(i-1)) + (i+2<=n && r && check(i+1)));
		a[i] = temp;
		// printf("%d %d\n",i,maxx);
	}
	cout << sum-maxx << '\n';
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
	}
	return 0;
}