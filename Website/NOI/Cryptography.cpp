/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
vector<LL > comp;
LL fact[300010],a[300010],tree[300010];
void update(LL idx,LL v){
	while(idx<=300000){
		tree[idx]+=v;
		idx+=idx & -idx;
	}
}
LL query(LL idx){
	LL sum = 0;
	while(idx>0){
		sum+=tree[idx];
		idx-=idx & -idx;
	}
	return sum;
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	LL n;
	cin >> n;
	fact[1] = 1;
	for(LL i=1;i<=n;i++){
		cin >> a[i];
		comp.push_back(a[i]);
		if(i == 1)	continue;
		fact[i] = (fact[i-1]*i)%MOD;
	}
	comp.push_back(0);
	sort(comp.begin(),comp.end());
	for(LL i=1;i<=n;i++)
		a[i] = lower_bound(comp.begin(),comp.end(),a[i])-comp.begin();
	LL ans = 1;
	for(LL i=1;i<n;i++){
		ans+=((a[i]-1-query(a[i]))*fact[n-i])%MOD;
		ans%=MOD;
		// printf("%d: %d\n",a[i],query(a[i]));
		update(a[i],1);
	}
	cout << ans << '\n';
	return 0;
}