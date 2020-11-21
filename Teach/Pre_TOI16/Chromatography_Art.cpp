/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: FW, BS, Sweep_Line
	Status	: Finished
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int ,int > PII;
typedef pair<long long ,long long > PLL;
struct A{
	int pos,h,v;
	bool operator < (const A&o) const{
		return pos<o.pos;
	}
};
vector<A > a;
int tree[1000010];
void upd(int idx,int v){
	while(idx<=1000003){
		tree[idx]+=v;
		idx+=idx & -idx;
	}
}
int query(int idx){
	int sum = 0;
	while(idx>0){
		sum+=tree[idx];
		idx-=idx & -idx;
	}
	return sum;
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,q,s,h,w,v,l,r,mid,c,st,en;
	LL ans = 0;
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> s >> h >> w >> v;
		a.push_back({s,h,v});
		a.push_back({s+w,h,-v});
	}
	a.push_back({0,0,0});
	a.push_back({4000001,0,0});
	sort(a.begin(),a.end());
	for(int i=0;i<a.size()-1;i++){
		while(i+1<a.size() && a[i].pos == a[i+1].pos){
			upd(1,a[i].v);
			upd(a[i].h+1,-a[i].v);
			i++;
		}
		upd(1,a[i].v);
		upd(a[i].h+1,-a[i].v);
		
		l = 1,r = 1000000;
		while(l<r){
			mid = (l+r)/2;
			c = query(mid);
			if(c>q)	l = mid+1;
			else	r = mid;
		}
		st = l;

		l = 1,r = 1000000;
		while(l<r){
			mid = (l+r)/2;
			c = query(mid);
			if(c>=q)	l = mid+1;
			else		r = mid;
		}
		en = l;

		ans+=(LL )(en-st)*(a[i+1].pos-a[i].pos);
		// printf("%d %d %d %d\n",a[i].pos,st,en,ans);
	}
	printf("%lld\n",ans);
	return 0;
}