/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	:
	Status	:
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
	if(b == 0)	return 0;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
int p[310],sum[310],mark[310];
int a[310],b[310];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,m,u;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> b[i];
		p[i] = i,sum[i] = 1;
		for(int j=i-1;j>=1;j--){
			if(a[j]<=a[i] && b[j]>=b[i]){
				p[i] = j;
				// printf("Father of %d is %d\n",i,j);
				break;
			}
		}
	}
	a[n+1] = b[n+1] = MAX_INT;
	while(m--){
		cin >> u;
		mark[u]++;
	}
	for(int i=n;i>=1;i--){
		if(p[i] == i)	continue;
		sum[p[i]]+=sum[i],mark[p[i]]+=mark[i];
	}
	// for(int i=1;i<=n;i++)
	// 	printf("%d ",mark[i]);
	// printf("\n");

	vector<int > v;
	for(int i=1;i<=n;i++){
		if(mark[i] == 0)	continue;
		// printf("%d\n",i);
		int maxx = 0,minn = 1e9,idx;
		for(int j=i;;j++){
			if(a[j]>b[i]){
				i = j-1;
				break;
			}
			maxx = max(maxx,mark[j]);
			if(mark[j] == maxx){
				if(minn>sum[j]-mark[j]){
					minn = sum[j]-mark[j];
					idx = j;
				}
			}
		}
		v.push_back(idx);
	}
	cout << v.size() << '\n';
	for(auto x:v)
		cout << x << ' ';
	return 0;
}