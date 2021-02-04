/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: BS, QS, GD
	Status	: Finished
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int ,int > PII;
typedef pair<long long ,long long > PLL;
vector<PII > v;
LL qs[200010],bs[200010];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q,n,a,l,r,mid;
	LL minn;
	cin >> q;
	while(q--){
		cin >> n;
		v.clear();
		for(int i=1;i<=n;i++){
			cin >> a;
			v.emplace_back(a,0);
		}
		for(int i=0;i<n;i++){
			cin >> a;
			v[i].second = -a;
		}
		sort(v.begin(),v.end());
		for(int i=0;i<n;i++){
			bs[i+1] = v[i].first;
			qs[i+1] = qs[i]-v[i].second;
		}
		// for(int i=1;i<=n;i++)
		// 	printf("%d ",bs[i]);
		// printf("\n");
		l = 0,r = n;
		while(l<r){
			mid = (l+r)/2;
			// printf("%d %d\n",bs[mid],qs[n]-qs[mid]);
			if(bs[mid]<qs[n]-qs[mid])		l = mid+1;
			else if(bs[mid]>qs[n]-qs[mid])	r = mid;
			else							l = r = mid;
		}
		minn = max(bs[l],qs[n]-qs[l]);
		l = 0,r = n;
		while(l<r){
			mid = (l+r+1)/2;
			// printf("%d %d\n",bs[mid],qs[n]-qs[mid]);
			if(bs[mid]<qs[n]-qs[mid])		l = mid;
			else if(bs[mid]>qs[n]-qs[mid])	r = mid-1;
			else							l = r = mid;
		}
		minn = min(minn,max(bs[l],qs[n]-qs[l]));
		cout << minn << '\n';
	}
	return 0;
}