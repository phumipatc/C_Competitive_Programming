/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL h[100010];
int l[100010],r[100010];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q,n;
	cin >> q;
	while(q--){
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> h[i];
		for(int i=1;i<=n;i++){
			l[i] = i-1;
			while(l[i]>0 && h[l[i]]>=h[i])
				l[i] = l[l[i]];
		}
		for(int i=n;i>=1;i--){
			r[i] = i+1;
			while(r[i]<=n && h[r[i]]>=h[i])
				r[i] = r[r[i]];
		}
		LL maxx = 0;
		for(int i=1;i<=n;i++)
			maxx = max(maxx,(r[i]-l[i]-1)*h[i]);
		cout << maxx << '\n';
	}
	return 0;
}