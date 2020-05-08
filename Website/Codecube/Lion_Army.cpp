/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD (LL )(1e9+7);
using namespace std;
typedef long long LL;
LL po[300010],sizee[300010];
pair<LL ,LL > p[300010];
LL fr(LL i){
	if(p[i].first == i)	return i;
	else				return p[i].first = fr(p[i].first);
}
LL mergee(LL u,LL v){
	if(sizee[u]>=sizee[v]){
		p[v].first = u;
		sizee[v]+=sizee[u];
		return v;
	}else{
		p[u].first = v;
		sizee[u]+=sizee[v];
		return u;
	}
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	LL n,m;
	LL zero = 0,countt;
	cin >> n >> m;
	countt = n;
	po[0] = 1;
	for(LL i=1;i<=n;i++){
		p[i] = {i,-1};
		sizee[i] = 1;
		po[i] = (2*po[i-1])%MOD;
	}
	LL opr,u,v;
	while(m--){
		if(zero){
			cout << "0\n";
			continue;
		}
		cin >> opr >> u >> v;
		LL ru = fr(u),rv =fr(v);
		if(opr == 0){
			if(ru == rv){
				zero = 1;
				printf("0\n");
				continue;
			}
			if(ru != p[rv].second){
				LL l,r;
				LL ruu = p[ru].second,rvv = p[rv].second;
				if(rvv!=-1)	l = mergee(rvv,ru);
				else					l = ru;
				if(ruu!=-1)	r = mergee(ruu,rv);
				else					r = rv;
				p[r].second = l,p[l].second = r;
				countt--;
			}
		}else{
			if(ru == p[rv].second){
				zero = 1;
				cout << "0\n";
				continue;
			}
			if(ru!=rv){
				LL l,r;
				LL ruu = p[ru].second,rvv = p[rv].second;
				if(ruu!=-1){
					if(rvv!=-1)	l = mergee(ruu,rvv);
					else	l = ruu;
				}else		l = rvv;
				r = mergee(ru,rv);
				// printf("%lld %lld\n",l,r);
				if(l!=-1)				p[r].second = l,p[l].second = r;
				countt--;
			}
		}
		// printf("%d\n",countt);
		cout << po[countt] << '\n';
		// for(LL i=1;i<=n;i++){
		// 	printf("%lld: %lld %lld\n",i,p[i].first,p[i].second);
		// }
	}
	return 0;
}