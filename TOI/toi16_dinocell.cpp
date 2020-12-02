/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Inclusion-Exclusion & Bitmask
	Status	: Unfinished [90 pt]
*/
#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
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
vector<int > pf;
int v[1000010];
int a[1000010];
int m;
int sum(int now){
	int sum = 0,bit;
	for(int i=1;i<(1<<m);i++){
		bit = __builtin_popcount(i);
		sum+=(bit%2)?now/v[i]:-now/v[i];
	}
	return sum;
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int z,k,n,now,p,pos,neg,last0,last1;	//0 = negative | 1 = positive
	LL maxx = -1e18;
	cin >> z >> k >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	
	now = k;
	for(int i=2;i<=sqrt(z);i++){
		if(now%i)	continue;
		pf.push_back(i);
		while(now%i == 0)	now/=i;
	}
	if(now!=1)	pf.push_back(now);
	
	m = pf.size();
	for(int i=1;i<(1<<m);i++){
		v[i] = 1;
		for(int j=0;j<m;j++)
			if(i&(1<<j))
				v[i]*=pf[j];
	}
	last0 = 1,last1 = -1;
	for(int i=2;i<=n;i++){
		pos = sum(a[i])-sum(a[i-1]);
		neg = (a[i]-a[i-1]) - pos;
		if(__gcd(a[i-1],k)>1)	p = 1;
		else					p = -1;
		// printf("%d %d %d %d\n",pos,neg,dp[i][0],dp[i][1]);
		maxx = maxN({maxx,max(neg-pos+last0,neg-pos-p),max(pos-neg + last1,pos-neg+p)});
		last0 = max(neg-pos+last0,neg-pos-p);
		last1 = max(pos-neg + last1,pos-neg+p);
	}
	cout << maxx << '\n';
	return 0;
}