/*
	Task	: PZ_Image
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 19 May 2021 [08:36]
	Algo	: Divide & Conquer
	Status	: Finished
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i <= (b); ++i)
#define repr(i, a, b) for(int i = a; i >= (b); --i)
#define all(x) begin(x),end(x)
#define allst(x,y) (x).begin()+y,(x).end()
#define rmdup(x) (x).resize(unique((x).begin(),(x).end())-(x).begin())
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
const int N = 520;
int qs[N][N];
int sum(int i,int j,int ii,int jj){
	return qs[ii][jj] - qs[i-1][jj] - qs[ii][j-1] + qs[i-1][j-1];
}
int ans = 0;
void div(int i,int j,int ii,int jj){
	if(sum(i,j,ii,jj) == 0 || sum(i,j,ii,jj) == (ii-i+1)*(jj-j+1)){
		ans+=2;
		return ;
	}
	// printf("Processing This\n");
	// rep(k,i,ii){
	// 	rep(l,j,jj){
	// 		printf("%d ",sum(k,l,k,l));
	// 	}
	// 	printf("\n");
	// }
	ans++;
	int mi = (i+ii)/2,mj = (j+jj)/2;
	// Left Down
	div(mi+1,j,ii,mj);
	// Left Up
	div(i,j,mi,mj);
	// Right Down
	div(mi+1,mj+1,ii,jj);
	// Right Up
	div(i,mj+1,mi,jj);
}
void solve(){
	int n;
	cin >> n;
	rep(i,1,n)
		rep(j,1,n)
			cin >> qs[i][j],qs[i][j]+=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
	ans = 0;
	div(1,1,n,n);
	cout << ans << '\n';
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int q = 1;
	cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}