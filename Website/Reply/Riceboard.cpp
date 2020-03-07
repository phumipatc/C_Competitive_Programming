/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL mod_of_pow(LL a,LL b,LL c){
	if(b == 0)	return 1ll;
	if(b == 1)	return a%c;
	LL p = mod_of_pow(a,b/2,c);
	if(b%2)		return (((p*p)%c)*(a%c))%c;
	else		return (p*p)%c;
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	LL q,r,n,m;
	cin >> q;
	for(int x=1;x<=q;x++){
		cin >> r >> n >> m;
		n*=n;
		if(r == 1){
			cout << "Case #" << x << ": ";
			cout << n%m << '\n';
			continue;
		}
		cout << "Case #" << x << ": ";
		cout << (((mod_of_pow(r,n,m)-1+m)%m)*mod_of_pow(r-1,m-2,m))%m << '\n';
	}
	return 0;
}
/*
1
930 585374422 991084756
*/