/*
	Task	: Disaster_Dragon
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 23 December 2022 [21:31]
	Algo	: FW + BS
	Status	: Finished
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i <= (b); ++i)
#define repr(i, a, b) for(int i = a; i >= (b); --i)
#define repl(i, a, b) for(LL i = a; i <= (b); ++i)
#define reprl(i, a, b) for(LL i = a; i >= (b); --i)
#define all(x) begin(x),end(x)
#define allst(x,y) (x).begin()+y,(x).end()
#define rmdup(x) sort(all(x)),(x).resize(unique((x).begin(),(x).end())-(x).begin())
#define sz(x) (int)(x).size()
#define decp(x) fixed << setprecision(x)
#define MOD (LL )(1e9+7)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2,c);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
const int N = 1e5+10;
int fw[N];
void upd(int x,int v){
	for(;x<N;x+=x&-x)
		fw[x]+=v;
}
int read(int x,int sum=0){
	for(;x>0;x-=x&-x)
		sum+=fw[x];
	return sum;
}
void init(){
	
}
void solve(){
	int n,q,low,high;
	cin >> n >> q >> low >> high;
	while(q--){
		int d,x,c,ar,al;
		cin >> d >> x >> c;
		if(d == 1)	upd(1,c),upd(x+1,-c);
		else		upd(x,-c),upd(n+1,c);
		int l=1,r=n;
		while(l<r){
			int mid = (l+r+1)/2;
			if(read(mid) >= low)	l = mid;
			else					r = mid-1;
		}
		if(l!=0 && read(l)>=low)	ar = l;
		else						ar = 0;
		l=1,r=n;
		while(l<r){
			int mid = (l+r)/2;
			if(read(mid) <= high)	r = mid;
			else					l = mid+1;
		}
		if(l!=n+1 && read(l)<=high)	al = l;
		else						al = n+1;
		if(ar < al)	cout << "-1\n";
		else{
			if(al == ar)	cout << al << '\n';
			else			cout << al << ' ' << ar << '\n';
		}
	}
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	// freopen("d:/Code/C_Programming/input.in","r",stdin);
	init();
	int q = 1;
	// cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}