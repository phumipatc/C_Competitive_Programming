/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[100010];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q,n,maxx,dif,bits;
	cin >> q;
	while(q--){
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		maxx = 0;
		for(int i=2;i<=n;i++){
			if(a[i]>=a[i-1])	continue;
			dif = a[i-1]-a[i],bits = ceil(log2(dif));
			// printf("%d\n",bits);
			if((1ll<<bits)-1>=dif)	maxx = max(maxx,bits);
			else					maxx = max(maxx,bits+1);
			a[i] = a[i-1];
		}
		cout << maxx << '\n';
	}
	return 0;
}