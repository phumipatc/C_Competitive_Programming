/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	LL q,x,y,a,b,l,r,mid,tx,ty,ans;
	cin >> q;
	while(q--){
		ans = -1;
		cin >> x >> y >> a >> b;
		l = 1,r = y-x;
		while(l<=r){
			mid = (l+r)/2;
			// printf("%lld\n",mid);
			tx = x+(a*mid);
			ty = y-(b*mid);
			if(tx>ty)		r = mid-1;
			else if(tx<ty)	l = mid+1;
			else{
				ans = mid;
				break;
			}
		}
		// printf("\n");
		cout << ans << '\n';
	}
	return 0;
}