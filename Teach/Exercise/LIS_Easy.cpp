/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int LIS[1010];
vector<int > seq[1010];
vector<int > ans;
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,num,idx,maxx = 0;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> num;
		idx = lower_bound(LIS,LIS+maxx,num)-LIS;
		if(idx == maxx)	maxx++;
		LIS[idx] = num;
		seq[idx].push_back(num);
	}
	int last = seq[maxx-1][0];
	ans.push_back(seq[maxx-1][0]);
	for(int i=maxx-2;i>=0;i--){
		for(auto x:seq[i]){
			if(x<last){
				last = x;
				ans.push_back(x);
				break;
			}
		}
	}
	reverse(ans.begin(),ans.end());
	cout << maxx << '\n';
	for(auto x:ans)
		cout << x << ' ';
	return 0;
}