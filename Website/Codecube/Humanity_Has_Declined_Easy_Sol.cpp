/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int minn[200010],a[200010],mapp[200010];
void solve(int n,int k){
	int l = n-k+1,r = n,countt = 0;
	for(int i=l+1;i<=r;i++){
		minn[i] = 1e9;
		if(!mapp[a[i]] && a[i]<=k)	countt++;
		mapp[a[i]]++;
	}
	while(l>0){
		if(!mapp[a[l]] && a[l]<=k)	countt++;
		mapp[a[l]]++;
		while(countt == k){
			if(mapp[a[r]] == 1 && a[r]<=k)	break;
			mapp[a[r]]--;
			r--;
		}
		if(countt == k)	minn[l] = r;
		else			minn[l] = 1e9;
		// printf("%d %d\n",l,minn[l]);
		l--;
	}
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,k,q;
	cin >> n >> k >> q;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	solve(n,k);
	int l,r;
	while(q--){
		cin >> l >> r;
		if(minn[l]<=r)	cout << "YES\n";
		else			cout << "NO\n";
	}
	return 0;
}