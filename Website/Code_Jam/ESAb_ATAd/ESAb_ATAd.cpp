/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	:
	Status	:
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
int n,l,r,last;
int a[110];
void rev(){
	for(int i=1;i<=n/2;i++)
		swap(a[i],a[n-i+1]);
}
void comp(){
	for(int i=1;i<=n;i++){
		if(a[i] == -1)	continue;
		a[i]^=1;
	}
}
void solve(){
	PII same = {0,0},diff = {0,0};
	int ll,retl,retr;
	l = 1,r = n,last = 1;
	memset(a,-1,sizeof a);
	for(int q=1;l<=r;q++){
		if(q>1 && q%10 == 1){
			if(same == make_pair(0,0)){
				cout << diff.first << '\n';
				fflush(stdout);
				cin >> retr;
				//Addition
				q++;
				cout << diff.first << '\n';
				fflush(stdout);
				cin >> retr;
				if(retr == a[diff.first])	continue;
				comp();
				continue;
			}
			cout << same.first << '\n';
			fflush(stdout);
			cin >> retl;
			if(diff == make_pair(0,0)){
				//Addition
				q++;
				cout << same.first << '\n';
				fflush(stdout);
				cin >> retl;
				if(retl == a[same.first])	continue;
				//Complemented
				comp();
			}else{
				q++;
				cout << diff.first << '\n';
				fflush(stdout);
				cin >> retr;
				if(retl == a[same.first] && retr != a[diff.first]){
					//Reversed
					rev();
				}else if(retl != a[same.first] &&  retr == a[diff.first]){
					//Reversed & Complemented
					rev();
					comp();
				}else if(retl != a[same.first] && retr != a[diff.first]){
					//Complemented;
					comp();
				}
			}
			continue;
		}
		if(last){
			cout << l << '\n';
			fflush(stdout);
			cin >> retl;
			a[l] = retl;
			if(a[n-l+1]!=-1){
				if(a[l] == a[n-l+1])	same = {l,n-l+1};
				else					diff = {l,n-l+1};
			}
			l++,last^=1;
		}else{
			cout << r << '\n';
			fflush(stdout);
			cin >> retr;
			a[r] = retr;
			if(a[n-r+1]!=-1){
				if(a[r] == a[n-r+1])	same = {n-r+1,r};
				else					diff = {n-r+1,r};
			}
			r--,last^=1;
		}
	}
	for(int i=1;i<=n;i++)
		cout << a[i];
	cout << '\n';
	fflush(stdout);
	char ans;
	cin >> ans;
	if(ans == 'N')	exit(0);
}
int main(){
	// ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q = 1;
	cin >> q >> n;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}