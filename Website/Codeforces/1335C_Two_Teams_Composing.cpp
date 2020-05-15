/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
set<int > sett;
int a[200010];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q,n,countt,maxx;
	cin >> q;
	while(q--){
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i];
			sett.insert(a[i]);
		}
		sort(a+1,a+n+1);
		maxx = a[n+1] = 0;
		for(int i=1;i<=n;i++){
			countt = 1;
			while(a[i] == a[i+1])	countt++,i++;
			maxx = max(maxx,countt);
		}
		cout << max(min((int )sett.size()-1,maxx),min((int )sett.size(),maxx-1)) << '\n';
		sett.clear();
	}
	return 0;
}