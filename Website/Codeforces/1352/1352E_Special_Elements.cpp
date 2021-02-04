/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[8010],mark[8010];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q,n,countt;
	cin >> q;
	while(q--){
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=1;i<=n;i++){
			a[i]+=a[i-1];
			for(int j=0;j<i-1;j++){
				if(a[i]-a[j]>n)	continue;
				mark[a[i]-a[j]] = 1;
			}
		}
		countt = 0;
		for(int i=1;i<=n;i++)
			countt+=mark[a[i]-a[i-1]];
		cout << countt << '\n';
		memset(mark,0,sizeof mark);
	}
	return 0;
}