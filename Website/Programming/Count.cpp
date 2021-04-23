/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Fenwick + BS
	Status	: Finished
*/
#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define allst(x,y) (x).begin()+y,(x).end()
#define decp(x) fixed << setprecision(x)
#define MOD (LL )(1e9+7)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
const int MAX_INT = 1e9;
const LL MAX_LL = 1e18;
LL minN(vector<LL > a){
	LL minn = 1e18;
	for(auto x:a)
		minn = min(minn,x);
	return minn;
}
LL maxN(vector<LL > a){
	LL maxx = -1e18;
	for(auto x:a)
		maxx = max(maxx,x);
	return maxx;
}
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 0;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
int tree[200010];
void upd(int idx,int v){
	while(idx<=200003){
		tree[idx]+=v;
		idx+=idx & -idx;
	}
}
int query(int idx,int sum = 0){
	while(idx>0){
		sum+=tree[idx];
		idx-=idx & -idx;
	}
	return sum;
}
void solve(){
	int n,k,pos,nowk,l,r,mid,qpos;
	cin >> n >> k;
	for(int i=1;i<=n;i++)
		upd(i,1);
	pos = k,upd(k,-1);
	for(int i=n-1;i>1;i--){
		nowk = (k%i)?k%i:i;
		// printf("nowk in %d:%d\n",i,nowk);
		qpos = query(pos);
		if(i-query(pos)){
			l = pos+1,r = n;
			while(l<r){
				mid = (l+r)/2;
				if(query(mid)-qpos)	r = mid;
				else				l = mid+1;
			}
			pos = l;
		}else{
			l = 1,r = pos-1;
			while(l<r){
				mid = (l+r)/2;
				if(query(mid))	r = mid;
				else			l = mid+1;
			}
			pos = l;
		}
		// printf("pos:%d\n",pos);
		qpos = query(pos-1);
		if(i-qpos>=nowk){
			l = pos,r = n;
			while(l<r){
				mid = (l+r)/2;
				if(query(mid)-qpos>=nowk)	r = mid;
				else						l = mid+1;
			}
			pos = k = l;
			upd(l,-1);
			// printf("ans:%d\n",l);
		}else{
			l = 1,r = pos;
			nowk-=i-qpos;
			while(l<r){
				mid = (l+r)/2;
				if(query(mid)>=nowk)	r = mid;
				else					l = mid+1;
			}
			pos = k = l;
			upd(l,-1);
			// printf("ans:%d\n",k);
		}
	}
	l = 1,r = n;
	while(l<r){
		mid = (l+r)/2;
		if(query(mid))	r = mid;
		else			l = mid+1;
	}
	cout << l << '\n';
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q = 1;
	// cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}