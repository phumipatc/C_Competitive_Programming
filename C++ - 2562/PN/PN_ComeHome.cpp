/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int p[300010],mark[300010];
int fr(int i){
	return (p[i] == i)?i:p[i] = fr(p[i]);
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,l,u,v,ru,rv;
	cin >> n >> l;
	for(int i=1;i<=l;i++)
		p[i] = i;
	while(n--){
		cin >> u >> v;
		ru = fr(u);
		rv = fr(v);
		if(!mark[u]){
			mark[u] = 1;
			p[ru] = rv;
			goto yes;
		}
		if(!mark[v]){
			mark[v] = 1;
			p[rv] = ru;
			goto yes;
		}
		if(!mark[ru]){
			mark[ru] = 1;
			p[ru] = rv;
			goto yes;
		}
		if(!mark[rv]){
			mark[rv] = 1;
			p[rv] = ru;
			goto yes;
		}
		cout << "No\n";
		continue;
		yes:cout << "Yes\n";
	}
	return 0;
}