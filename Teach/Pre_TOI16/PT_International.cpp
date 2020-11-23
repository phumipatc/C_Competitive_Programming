/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: 2 Pointers
	Status	: Finished
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int ,int > PII;
typedef pair<long long ,long long > PLL;
PII a[50010];
map<int ,int > mapp;
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q,n,m,l,countt,minn;
	cin >> q;
	while(q--){
		cin >> n;
		mapp.clear();
		for(int i=1;i<=n;i++){
			cin >> a[i].first >> a[i].second;
			mapp[a[i].second]++;
		}
		m = mapp.size();
		mapp.clear();
		sort(a+1,a+n+1);
		countt = 0,l = 1,minn = 1e9;
		for(int i=1;i<=n;i++){
			if(!mapp[a[i].second])	countt++;
			mapp[a[i].second]++;
			while(countt == m){
				// printf("%d %d\n",l,i);
				minn = min(minn,a[i].first-a[l].first+1);
				mapp[a[l].second]--;
				if(!mapp[a[l].second])	countt--;
				l++;
			}
		}
		cout << minn << '\n';
	}
	return 0;
}
