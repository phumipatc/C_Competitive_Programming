/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: FW tree
	Status	: Finished
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int ,int > PII;
typedef pair<long long ,long long > PLL;
PII a[100010];
LL tree[2][100010];
void upd(int x,int idx,int v){
	while(idx<=100003){
		tree[x][idx]+=v;
		idx+= idx & -idx;
	}
}
LL query(int x,int idx){
	LL sum = 0;
	while(idx>0){
		sum+=tree[x][idx];
		idx-=idx & -idx;
	}
	return sum;
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n;
	LL ans = 0;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i].second >> a[i].first;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ans+=a[i].second*(query(0,100000)-query(0,a[i].second));
		ans+=query(1,100000)-query(1,a[i].second);
		upd(0,a[i].second,1);
		upd(1,a[i].second,a[i].second);
	}
	cout << ans << '\n';
	return 0;
}