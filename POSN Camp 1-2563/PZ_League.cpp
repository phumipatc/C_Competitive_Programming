/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	:
	Status	:
*/
#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define allst(x,y) (x).begin()+y,(x).end()
#define sz(x) (int)(x).size()
#define decp(x) fixed << setprecision(x)
#define MOD (LL )(1e9+7)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
const int MAX_INT = 1e9;
const LL MAX_LL = 1e18;
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 0;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
struct A{
	string str;
	int v,dif,w,l,t;
	bool operator < (const A&o) const{
		if(v!=o.v)			return v>o.v;
		else if(dif!=o.dif)	return dif>o.dif;
		else				return str<o.str;
	}
};
A p[1010];
int a[1010][1010];
void cal(int win,int lose,int v){
	p[win].w++,p[lose].l++;
	p[win].dif+=v,p[lose].dif-=v;
	p[win].v+=3;
}
int n;
void solve(){
	string ask;
	cin >> ask;
	for(int i=1;i<=n;i++){
		if(ask!=p[i].str)	continue;
		cout << i << ' ' << p[i].w << ' ' << p[i].t << ' ' << p[i].l << '\n';
		return ;
	}
	cout << "Error\n";
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> p[i].str;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin >> a[i][j];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i][j] == a[j][i])		p[i].t++,p[j].t++,p[i].v++,p[j].v++;
			else if(a[i][j]<a[j][i])	cal(j,i,a[j][i]-a[i][j]);
			else						cal(i,j,a[i][j]-a[j][i]);
		}
	}
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++)
		cout << p[i].str << ' ' << p[i].v << ' ' << p[i].dif << '\n';
	int q = 1;
	cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}
/*
5
Liver
ManU
ManCity
Asenal
Spurs
0 1 1 1 0
1 0 1 3 2
4 2 0 3 2
4 1 2 0 1
2 3 1 2 0
2
ManCity
Liverr
*/