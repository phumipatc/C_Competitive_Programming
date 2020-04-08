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
	int q,s,p;
	cin >> q;
	while(q--){
		cin >> s >> p;
		int l=1,r = (s+1)/2,mid;
		while(l<=r){
			mid = (l+r)/2;
			// printf("%d*%d = %d\n",mid,s-mid,mid*(s-mid));
			if(mid*(s-mid)>p)		r = mid-1;
			else if(mid*(s-mid)<p)	l = mid+1;
			else{
				l = r = mid;
				break;
			}
		}
		if(l*(s-l) == p)	cout << min(l,s-l) << ' ' << max(l,s-l) << '\n';
		else				cout << "No answer\n";
	}
	return 0;
}