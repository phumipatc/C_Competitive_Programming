/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD (int )(1e9+7)
using namespace std;
typedef long long LL;
int p[300010],op[300010],po[300010];
int fr(int i){
	return p[i] = (p[i] == i)?i:fr(p[i]);
}
int gr,impos;
void solve(){
	int opr,u,v,ru,rv;
	cin >> opr >> u >> v;
	if(impos){
		cout << "0\n";
		return ;
	}
	ru = fr(u),rv = fr(v);
	if(opr == 0){
		if(ru == rv){
			impos = 1;
			cout << "0\n";
			return ;
		}
		if(op[ru])	op[ru] = fr(op[ru]);
		if(op[rv])	op[rv] = fr(op[rv]);
		if(ru == op[rv] || rv == op[ru]);
		else{
			gr--;
			if(op[rv])	p[ru] = op[rv];
			if(op[ru])	p[rv] = op[ru];
			ru = fr(ru),rv = fr(rv);
			if(op[ru])	p[op[ru]] = rv;
			if(op[rv])	p[op[rv]] = ru;
			op[ru] = rv,op[rv] = ru;
		}
	}else{
		if(op[ru])	op[ru] = fr(op[ru]);
		if(op[rv])	op[rv] = fr(op[rv]);
		if(ru == op[rv] || rv == op[ru]){
			impos = 1;
			cout << "0\n";
			return ;
		}
		if(ru == rv);
		else{
			gr--;
			if(op[ru] && op[rv]){
				p[op[ru]] = op[rv];
				op[ru] = op[rv];
				p[ru] = rv;
			}else if(op[ru]){
				op[rv] = op[ru];
				p[rv] = ru;
			}else if(op[rv]){
				op[ru] = op[rv];
				p[ru] = rv;
			}else{
				p[ru] = rv;
			}
		}
	}
	// printf("%d\n",gr);
	cout << po[gr] << '\n';
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	gr = n;
	po[0] = 1;
	for(int i=1;i<=n;i++){
		p[i] = i;
		po[i] = (2*po[i-1])%MOD;
		// printf("%d %d\n",i,po[i]);
	}
	while(m--){
		solve();
	}
	return 0;
}