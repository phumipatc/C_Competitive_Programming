/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[110],b[110];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q,n,m;
	cin >> q;
	while(q--){
		cin >> n >> m;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=1;i<=m;i++)
			cin >> b[i];
		b[m+1] = 0;
		sort(b+1,b+m+1);
		int st = 1;
		for(int i=1;i<=m;i++){
			if(b[i]+1 != b[i+1]){
				sort(a+b[st],a+b[i]+2);
				st = i+1;
			}
		}
		int ch = 1;
		for(int i=1;i<n;i++){
			if(a[i]<=a[i+1])	continue;
			ch = 0;
			break;
		}
		if(ch)	cout << "YES\n";
		else	cout << "NO\n";
	}
	return 0;
}