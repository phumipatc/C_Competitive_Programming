/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int > a,ans;
vector<pair<int ,int > > seq[100010];
int LIS[100010];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,num,maxx = 0,idx;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> num;
		a.push_back(num);
	}
	reverse(a.begin(),a.end());
	for(int i=0;i<a.size();i++){
		int x = a[i];
		idx = lower_bound(LIS,LIS+maxx,x)-LIS;
		if(idx == maxx)	maxx++;
		LIS[idx] = x;
		seq[idx].push_back({x,i});
	}
	for(int i=0;i<maxx;i++)
		reverse(seq[i].begin(),seq[i].end());
	pair<int ,int > last = seq[maxx-1][0];
	ans.push_back(last.first);
	for(int i=maxx-2;i>=0;i--){
		for(auto x:seq[i]){
			if(x.first<last.first && x.second<last.second){
				last = x;
				ans.push_back(x.first);
			}
		}
	}
	cout << maxx << '\n';
	for(auto x:ans)
		cout << x << ' ';
	return 0;
}