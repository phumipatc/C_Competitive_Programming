/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
set<LL > sett;
LL  a[300010],b[300010];
LL l[300010],tree[300010];
void update(LL  idx,LL  v){
	// printf("Update started\n");
	while(idx<=300000){
		// printf("%d\n");
		tree[idx]+=v;
		idx+=idx & -idx;
	}
}
LL query(LL  idx){
	// printf("Query started\n");
	LL sum = 0;
	while(idx>0){
		// printf("%d\n",idx);
		sum+=tree[idx];
		idx-=idx & -idx;
	}
	return sum;
}
int main(){
	ios_base::sync_with_stdio(0);
	LL n;
	cin >> n;
	for(LL  i=1;i<=n;i++){
		cin >> a[i];
		sett.insert(a[i]);
	}
	LL num = 1,ans = 0;
	for(auto x:sett)
		b[num++] = x;
	for(LL  i=1;i<=n;i++){
		num = lower_bound(b+1,b+sett.size()+1,a[i])-b;
		l[i] = query(num-1);
		update(num,1);
	}
	memset(tree,0,sizeof tree);
	for(LL  i=n;i>=1;i--){
		num = lower_bound(b+1,b+sett.size()+1,a[i])-b;
		ans+=l[i]*query(num-1);
		update(num,1);
	}
	cout << ans << '\n';
	return 0;
}