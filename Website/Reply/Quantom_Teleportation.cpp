/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 100003
using namespace std;
typedef long long LL;
struct A{
	int stx,sty,enx,eny;
};
A a[2010];
pair<int ,int > pos;
int dis(A a,A b){
	return abs(b.stx-a.enx)+abs(b.sty-a.eny);
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	freopen("input-teleportation-bb53.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,r,c,n;
	cin >> t;
	for(int x=1;x<=t;x++){
		cin >> r >> c >> a[0].enx >> a[0].eny;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i].stx >> a[i].sty >> a[i].enx >> a[i].eny;
		int ans = 0;
		for(int i=0;i<n;i++){
			int minn = 1e9,idx;
			for(int j=i+1;j<=n;j++){
				if(minn>dis(a[i],a[j])){
					minn = dis(a[i],a[j]);
					idx = j;
				}else if(minn == dis(a[i],a[j])){
					if(a[idx].stx<a[j].stx)	continue;
					if(a[idx].stx>a[j].stx){
						idx = j;
						continue;
					}
					if(a[idx].sty<a[j].sty)	continue;
					if(a[idx].sty>a[j].sty){
						idx = j;
						continue;
					}
				}
			}
			ans+=minn;
			ans%=MOD;
			swap(a[i+1],a[idx]);
		}
		cout << "Case #" << x << ": " << ans << '\n';
	}
	return 0;
}