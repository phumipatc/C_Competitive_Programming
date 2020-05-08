/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct A{
	int st,en,id;
	bool operator < (const A&o) const{
		if(en!=o.en)	return en<o.en;
		else			return st<o.st;
	}
};
A Q[200010];
int a[200010],mapp[200010],ans[200010];
vector<A > v[500];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,k,q,sq = sqrt(200000);
	cin >> n >> k >> q;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=q;i++){
		cin >> Q[i].st >> Q[i].en;
		Q[i].id = i;
		v[Q[i].st/sq].push_back(Q[i]);
	}
	for(int i=0;i<=sq;i++){
		sort(v[i].begin(),v[i].end());
		if(v[i].size() == 0)	continue;
		int l = v[i][0].st,r = v[i][0].st,countt = 0;
		for(auto x:v[i]){
			// printf("## %d %d %d\n",x.st,x.en,x.id);
			while(r<=x.en){
				if(!mapp[a[r]] && a[r]<=k)	countt++;
				mapp[a[r]]++;
				r++;
			}
			while(l<x.st){
				mapp[a[l]]--;
				if(!mapp[a[l]] && a[l]<=k)	countt--;
				l++;
			}
			while(l>x.st){
				l--;
				if(!mapp[a[l]] && a[l]<=k)	countt++;
				mapp[a[l]]++;
			}
			// printf("%d\n",countt);
			if(countt == k)	ans[x.id] = 1;
			else			ans[x.id] = 0;
			// printf("%d\n",ans[x.id]);
		}
		memset(mapp,0,sizeof mapp);
	}
	for(int i=1;i<=q;i++){
		if(ans[i])	cout << "YES\n";
		else		cout << "NO\n";
	}
	return 0;
}