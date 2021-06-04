/*
	Task	: goldenland
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 26 May 2021 [14:30]
	Algo	: 
	Status	: 
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
const int mxN = 60010;
bool seive[(int )1e6+10];
vector<int > p;
void gen_prime(){
	rep(i,2,sqrt(1e6)){
		if(seive[i])	continue;
		p.push_back(i);
		for(int j=i*i;j<=1e6;j+=i)
			seive[j] = true;
	}
}
map<int ,int > g;
vector<int > posA[2*mxN],posB[2*mxN];
vector<int > a,b;
int cnt;
LL sum = 0;
void init_land(int N, int M, int P, std::vector<int> A, std::vector<int> B){
	
	gen_prime();
	for(auto &x:A){
		for(auto y:p){
			if(y*y>x)	break;
			while((x%(y*y)) == 0)	x/=(y*y);
		}
		if(g.find(x) == g.end())	g[x] = ++cnt;
	}
	rep(i,0,sz(A)-1)
		posA[g[A[i]]].push_back(i);
	for(auto &x:B){
		for(auto y:p){
			if(y*y>x)	break;
			while((x%(y*y)) == 0)	x/=(y*y);
		}
		if(g.find(x) == g.end())	g[x] = ++cnt;
	}
	rep(i,0,sz(B)-1)
		posB[g[B[i]]].push_back(i);
	a = A,b = B;
	rep(i,1,cnt){
		int a = upper_bound(all(posA[i]),N)-posA[i].begin();
		int b = lower_bound(all(posA[i]),0)-posA[i].begin();
		int c = upper_bound(all(posB[i]),M)-posB[i].begin();
		int d = lower_bound(all(posB[i]),0)-posB[i].begin();
		sum+=(LL )(a-b)*(c-d);
	}
}

long long answer_query(int r1, int c1, int r2, int c2){
	if(sum == 0)	return 0;
	LL ans = 0;
	int minn = min({r2-r1+1,c2-c1+1,cnt});
	if(r2-r1+1 == minn){
		rep(i,r1,r2){
			int c = upper_bound(all(posB[g[a[i]]]),c2)-posB[g[a[i]]].begin();
			int d = lower_bound(all(posB[g[a[i]]]),c1)-posB[g[a[i]]].begin();
			ans+=c-d;
		}
	}else if(c2-c1+1 == minn){
		rep(i,c1,c2){
			int c = upper_bound(all(posA[g[b[i]]]),r2)-posA[g[b[i]]].begin();
			int d = lower_bound(all(posA[g[b[i]]]),r1)-posA[g[b[i]]].begin();
			ans+=c-d;
		}
	}else{
		rep(i,1,cnt){
			if(posA[i].empty() || posB[i].empty())		continue;
			if(posA[i].back()<r1 || posA[i].front()>r2)	continue;
			if(posB[i].back()<c1 || posB[i].front()>c2)	continue;
			int a = upper_bound(all(posA[i]),r2)-posA[i].begin();
			int b = lower_bound(all(posA[i]),r1)-posA[i].begin();
			if(a-b == 0)	continue;
			int c = upper_bound(all(posB[i]),c2)-posB[i].begin();
			int d = lower_bound(all(posB[i]),c1)-posB[i].begin();
			ans+=(LL )(a-b)*(c-d);
		}
	}
	sum-=ans;
	return ans;
}

