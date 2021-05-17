/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Permutation, BS, Split array into k subarray with minimum sum for each subarray
	Status	: Finished
*/
#include<bits/stdc++.h>
// #include<conio.h>
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
vector<LL > a,b,c,minn;
LL w[10000010];
int t[12],st[12];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,m,q,countt,ch;
	LL l,r,mid,sum;
	cin >> n >> m >> q;
	a.resize(n);
	b.resize(n);
	c.resize(n);
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<n;i++)
		cin >> b[i];
	for(int i=1;i<=m;i++)
		cin >> w[i],w[i]+=w[i-1];
	for(int i=1;i<=q;i++)
		cin >> t[i];
	sort(a.begin(),a.end());
	int ll,rr,midd;
	for(int Q=1;Q<=q;Q++){
		for(int i=1;i<=n;i++)
			cin >> st[i];
		st[n+1] = m+1;
		minn.clear();
		for(int i=1;i<=n;i++){
			l = 0,r = w[st[i+1]-1];
			for(int j=st[i];j<st[i+1];j++)
				l = max(l,w[j]-w[j-1]);
			while(l<r){
				mid = (l+r)/2,countt = 0,sum = 0;
				for(int j=st[i+1]-1;j>=st[i];){
					ll = st[i]-1,rr = j;
					while(ll<rr){
						midd = (ll+rr)/2;
						// printf("%d %d %d %d %lld\n",j,ll,rr,midd,w[j]-w[midd]);
						if(w[j]-w[midd]>mid)	ll = midd+1;
						else					rr = midd;
					}
					j = midd;
					countt++;
				}
				if(countt>t[Q])	l = mid+1;
				else			r = mid;
			}
			// printf("%lld\n",l);
			minn.push_back(l);
		}
		sort(minn.begin(),minn.end());
		// for(auto x:minn)
		// 	printf("%d\n",x);
		sort(b.begin(),b.end());
		do{
			for(int i=0;i<n;i++)
				c[i] = a[i]-b[i];
			sort(c.begin(),c.end());
			ch = 1;
			for(int i=0;i<n;i++){
				if(minn[i]>c[i]){
					ch = 0;
					break;
				}
			}
			if(ch){
				cout << "P\n";
				break;
			}
		}while(next_permutation(b.begin(),b.end()));
		if(!ch)	cout << "F\n";
	}
	return 0;
}